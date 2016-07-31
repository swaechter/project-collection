#include "ProjectManager.h"

ProjectManager::ProjectManager(QObject *parent): QObject(parent)
{
	m_Project = new Project();
}

ProjectManager::~ProjectManager()
{
	delete m_Project;
}

Project *ProjectManager::createProject(QString name, QString directory, QStringList files)
{
	if(!getProject())
	{
		directory = directory.append(QString("/")) + name + QString("/");
		
		m_Project->setName(name);
		m_Project->setLocation(directory);
		
		Backend::createDirectory(directory);
		Backend::createFile(directory + QString("Project.cdev"));
		Backend::writeFile(directory + QString("Project.cdev"), name);
		foreach(QString file, files)
		{
			QString filepath = directory + Backend::getNameOfFile(file);
			Backend::createFile(filepath);
			Backend::writeFile(filepath, Backend::readFile(file));
		}
		
		emit projectOpened();
		
		return m_Project;
	}
	return nullptr;
}

Project *ProjectManager::openProject(QString projectfile)
{
	if(!getProject())
	{
		QString projectdirectory = Backend::getDirectoryOfFile(projectfile) + QString("/");
		QString projectname = Backend::readFile(projectfile);
		if(!projectdirectory.isEmpty() && !projectname.isEmpty())
		{
			m_Project->setName(projectname);
			m_Project->setLocation(projectdirectory);
			emit projectOpened();
			return m_Project;
		}
	}
	return nullptr;
}

Project *ProjectManager::getProject()
{
	if(!m_Project->getName().isEmpty() && !m_Project->getLocation().isEmpty())
	{
		return m_Project;
	}
	return nullptr;
}

bool ProjectManager::closeProject()
{
	if(getProject())
	{
		foreach(QString file, m_Project->getFiles())
		{
			closeFile(file);
		}
		m_Project->setName(QString());
		m_Project->setLocation(QString());
		emit projectClosed();
	}
	return true;
}

bool ProjectManager::createFile(QString file)
{
	if(getProject() && !file.isEmpty() && !Backend::doesPathExist(m_Project->getLocation() + file))
	{
		return Backend::createFile(m_Project->getLocation() + file);
	}
	return false;
}

bool ProjectManager::openFile(QString file)
{
	if(getProject() && !file.isEmpty() && Backend::doesPathExist(m_Project->getLocation() + file) && !Backend::isPathADirectory(m_Project->getLocation() + file))
	{
		if(!m_Project->getFiles().contains(file))
		{
			m_Project->addFile(file);
			emit fileOpened(file);
		}
		else
		{
			emit fileReopened(file);
		}
		return true;
	}
	return false;
}

bool ProjectManager::deleteFile(QString file)
{
	if(getProject() && !file.isEmpty() && Backend::doesPathExist(m_Project->getLocation() + file))
	{
		if(closeFile(file) && Backend::deleteFile(m_Project->getLocation() + file))
		{
			return true;
		}
	}
	return false;
}

bool ProjectManager::renameFile(QString oldfile, QString newfile)
{
	if(getProject() && !oldfile.isEmpty() && !newfile.isEmpty() && Backend::doesPathExist(m_Project->getLocation() + oldfile))
	{
		if(closeFile(oldfile) && Backend::renameFile(m_Project->getLocation() + oldfile, newfile) && openFile(newfile))
		{
			return true;
		}
	}
	return false;
}

bool ProjectManager::writeFile(QString file, QString text)
{
	if(getProject() && !file.isEmpty() && Backend::doesPathExist(m_Project->getLocation() + file))
	{
		return Backend::writeFile(m_Project->getLocation() + file, text);
	}
	return false;
}

bool ProjectManager::closeFile(QString file)
{
	if(getProject() && !file.isEmpty() && m_Project->getFiles().contains(file))
	{
		m_Project->removeFile(file);
		emit fileClosed(file);
		return true;
	}
	return false;
}

bool ProjectManager::isFilepathInProject(QString filepath)
{
	return filepath.startsWith(m_Project->getLocation());
}
