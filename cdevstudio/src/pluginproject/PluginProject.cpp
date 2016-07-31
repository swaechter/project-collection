#include "PluginProject.h"

PluginProject::PluginProject()
{
	m_Platform = IPlatform::getInstance();
	
	Window *window = m_Platform->getWindow();
	PluginPage *pluginpage = new PluginPage(window->getSettingsDialog());
	window->getSettingsDialog()->addSettingsPage(pluginpage);
	
	m_ActionCreateProject = new QAction(tr("Create Project"), window->getMenuBar());
	m_ActionOpenProject = new QAction(tr("Open Project"), window->getMenuBar());
	m_ActionCloseProject = new QAction(tr("Close Project"), window->getMenuBar());
	m_ActionCreateFile = new QAction(tr("Create File"), window->getMenuBar());
	m_ActionOpenFile = new QAction(tr("Open File"), window->getMenuBar());
	m_ActionDeleteFile = new QAction(tr("Delete File"), window->getMenuBar());
	m_ActionRenameFile = new QAction(tr("Rename File"), window->getMenuBar());
	m_ActionSaveFile = new QAction(tr("Save File"), window->getMenuBar());
	m_ActionCloseFile = new QAction(tr("Close File"), window->getMenuBar());
	
	m_ActionCreateProject->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_N);
	m_ActionOpenProject->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_O);
	m_ActionCloseProject->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_Q);
	m_ActionCreateFile->setShortcut(Qt::CTRL | Qt::Key_N);
	m_ActionOpenFile->setShortcut(Qt::CTRL | Qt::Key_O);
	m_ActionDeleteFile->setShortcut(Qt::CTRL | Qt::Key_D);
	m_ActionRenameFile->setShortcut(Qt::CTRL | Qt::Key_R);
	m_ActionSaveFile->setShortcut(Qt::CTRL | Qt::Key_S);
	m_ActionCloseFile->setShortcut(Qt::CTRL | Qt::Key_Q);
	
	window->getMenuBar()->getMenu(tr("Project"))->addAction(m_ActionCreateProject);
	window->getMenuBar()->getMenu(tr("Project"))->addAction(m_ActionOpenProject);
	window->getMenuBar()->getMenu(tr("Project"))->addAction(m_ActionCloseProject);
	window->getMenuBar()->getMenu(tr("File"))->addAction(m_ActionCreateFile);
	window->getMenuBar()->getMenu(tr("File"))->addAction(m_ActionOpenFile);
	window->getMenuBar()->getMenu(tr("File"))->addAction(m_ActionDeleteFile);
	window->getMenuBar()->getMenu(tr("File"))->addAction(m_ActionRenameFile);
	window->getMenuBar()->getMenu(tr("File"))->addSeparator();
	window->getMenuBar()->getMenu(tr("File"))->addAction(m_ActionSaveFile);
	window->getMenuBar()->getMenu(tr("File"))->addSeparator();
	window->getMenuBar()->getMenu(tr("File"))->addAction(m_ActionCloseFile);
	
	connect(m_ActionCreateProject, SIGNAL(triggered(bool)), this, SLOT(actionCreateProjectTrigger()));
	connect(m_ActionOpenProject, SIGNAL(triggered(bool)), this, SLOT(actionOpenProjectTrigger()));
	connect(m_ActionCloseProject, SIGNAL(triggered(bool)), this, SLOT(actionCloseProjectTrigger()));
	connect(m_ActionCreateFile, SIGNAL(triggered(bool)), this, SLOT(actionCreateFileTrigger()));
	connect(m_ActionOpenFile, SIGNAL(triggered(bool)), this, SLOT(actionOpenFileTrigger()));
	connect(m_ActionDeleteFile, SIGNAL(triggered(bool)), this, SLOT(actionDeleteFileTrigger()));
	connect(m_ActionRenameFile, SIGNAL(triggered(bool)), this, SLOT(actionRenameFileTrigger()));
	connect(m_ActionSaveFile, SIGNAL(triggered(bool)), this, SLOT(actionSaveFileTrigger()));
	connect(m_ActionCloseFile, SIGNAL(triggered(bool)), this, SLOT(actionCloseFileTrigger()));
}

PluginProject::~PluginProject()
{
}

void PluginProject::actionCreateProjectTrigger()
{
	if(!m_Platform->getProjectManager()->getProject())
	{
		QList<ProjectTemplate> templates;
		templates.append(ProjectTemplate(tr("Empty Project"), tr("An empty project"), QStringList()));
		templates.append(ProjectTemplate(tr("C Hello World"), tr("A simple C 'Hello World' example"), QStringList() << ":/data/templatec/CMakeLists.txt" << ":/data/templatec/main.c"));
		templates.append(ProjectTemplate(tr("C++ Hello World"), tr("A simple C++ 'Hello World' example"), QStringList() << ":/data/templatecplusplus/CMakeLists.txt" << ":/data/templatecplusplus/main.cpp"));
		
		CreateProjectDialog *dialog = new CreateProjectDialog(templates, m_Platform->getWindow());
		if(dialog->exec() == QDialog::Accepted)
		{
			if(!dialog->getProjectName().isEmpty() && !dialog->getProjectName().isEmpty() && !dialog->getProjectLocation().isEmpty())
			{
				foreach(ProjectTemplate projecttemplate, templates)
				{
					if(projecttemplate.getName().compare(dialog->getTemplateName()) == 0)
					{
						if(!m_Platform->getProjectManager()->createProject(dialog->getProjectName(), dialog->getProjectLocation(), projecttemplate.getFiles()))
						{
							QMessageBox::critical(m_Platform->getWindow(), tr("Error"), tr("The system was unable to create the project."));
						}
						break;
					}
				}
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Please close the current project before you create a new one."));
	}
}

void PluginProject::actionOpenProjectTrigger()
{
	if(!m_Platform->getProjectManager()->getProject())
	{
		QString projectfile = QFileDialog::getOpenFileName(m_Platform->getWindow(), tr("Open project"), QDir::homePath(), tr("Project (*.cdev)"));
		if(!projectfile.isEmpty())
		{
			if(!m_Platform->getProjectManager()->openProject(projectfile))
			{
				QMessageBox::critical(m_Platform->getWindow(), tr("Error"), tr("The system was unable to open the project."));
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Please close the current project before you open a new one."));
	}
}

void PluginProject::actionCloseProjectTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		m_Platform->getProjectManager()->closeProject();
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("There is no active project to close."));
	}
}

void PluginProject::actionCreateFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		QString filepath = QFileDialog::getSaveFileName(m_Platform->getWindow(), tr("Create a new file"), m_Platform->getProjectManager()->getProject()->getLocation());
		if(!filepath.isEmpty() && m_Platform->getProjectManager()->isFilepathInProject(filepath))
		{
			QString file = filepath.remove(m_Platform->getProjectManager()->getProject()->getLocation());
			if(!m_Platform->getProjectManager()->createFile(file) || !m_Platform->getProjectManager()->openFile(file))
			{
				QMessageBox::critical(m_Platform->getWindow(), tr("Error"), tr("The system was unable to create and open the file."));
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Please create or open a project."));
	}
}

void PluginProject::actionOpenFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		QString filepath = QFileDialog::getOpenFileName(m_Platform->getWindow(), tr("Open a file"), m_Platform->getProjectManager()->getProject()->getLocation());
		if(!filepath.isEmpty() && m_Platform->getProjectManager()->isFilepathInProject(filepath))
		{
			QString file = filepath.remove(m_Platform->getProjectManager()->getProject()->getLocation());
			if(!m_Platform->getProjectManager()->openFile(file))
			{
				QMessageBox::critical(m_Platform->getWindow(), tr("Error"), tr("The system was unable to open the file."));
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Please create or open a project."));
	}
}

void PluginProject::actionDeleteFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		int index = m_Platform->getWindow()->getTabWidget()->currentIndex();
		if(index != -1)
		{
			QString file = m_Platform->getWindow()->getTabWidget()->tabText(index);
			if(QMessageBox::question(m_Platform->getWindow(), tr("Delete"), tr("Do you want to delete the current file?")) == QMessageBox::Yes)
			{
				if(!m_Platform->getProjectManager()->deleteFile(file))
				{
						QMessageBox::critical(m_Platform->getWindow(), tr("Error"), tr("The system was unable to delete the current file."));
				}
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Please create or open a project."));
	}
}

void PluginProject::actionRenameFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		int index = m_Platform->getWindow()->getTabWidget()->currentIndex();
		if(index != -1)
		{
			bool result = false;
			QString file = m_Platform->getWindow()->getTabWidget()->tabText(index);
			QString filepath = m_Platform->getProjectManager()->getProject()->getLocation() + file;
			QStringList fileparts = filepath.split("/");
			QString text = fileparts.at(fileparts.count() - 1);
			QString newtext = QInputDialog::getText(m_Platform->getWindow(), tr("Rename"), tr("New file name"), QLineEdit::Normal, text, &result);
			if(result && !newtext.isEmpty())
			{
				fileparts.removeLast();
				fileparts.append(newtext);
				QString newfilepath = fileparts.join("/");
				QString newfile = newfilepath.remove(m_Platform->getProjectManager()->getProject()->getLocation());
				if(!m_Platform->getProjectManager()->renameFile(file, newfile))
				{
					QMessageBox::critical(m_Platform->getWindow(), tr("Error"), tr("The system was unable to rename the current file."));
				}
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Please create or open a project."));
	}
}

void PluginProject::actionSaveFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		int index = m_Platform->getWindow()->getTabWidget()->currentIndex();
		if(index != -1)
		{
			QString file = m_Platform->getWindow()->getTabWidget()->tabText(index);
			QTextEdit *textedit = m_Platform->getWindow()->getTabWidget()->getTextEdit(file);
			if(textedit)
			{
				QString text = textedit->toPlainText();
				if(!m_Platform->getProjectManager()->writeFile(file, text))
				{
					QMessageBox::critical(m_Platform->getWindow(), tr("Error"), tr("The system was unable to write the current file."));
				}
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Please create or open a project."));
	}
}

void PluginProject::actionCloseFileTrigger()
{
	if(m_Platform->getProjectManager()->getProject())
	{
		int index = m_Platform->getWindow()->getTabWidget()->currentIndex();
		if(index != -1)
		{
			QString file = m_Platform->getWindow()->getTabWidget()->tabText(index);
			if(!m_Platform->getProjectManager()->closeFile(file))
			{
				QMessageBox::critical(m_Platform->getWindow(), tr("Error"), tr("The system was unable to close the current file."));
			}
		}
	}
	else
	{
		QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Please create or open a project."));
	}
}
