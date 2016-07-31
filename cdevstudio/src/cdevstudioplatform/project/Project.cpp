#include "Project.h"

QString Project::getName()
{
	return m_Name;
}

QString Project::getLocation()
{
	return m_Location;
}

QString Project::getProjectFile()
{
	return m_Location + QString("Project.cdev");
}

QStringList Project::getFiles()
{
	return m_Files;
}

void Project::setName(QString name)
{
	m_Name = name;
}

void Project::setLocation(QString location)
{
	m_Location = location;
}

void Project::setFiles(QStringList files)
{
	m_Files = files;
	m_Files.removeDuplicates();
}

void Project::addFile(QString file)
{
	if(!m_Files.contains(file))
	{
		m_Files.append(file);
	}
}

void Project::removeFile(QString file)
{
	m_Files.removeOne(file);
}
