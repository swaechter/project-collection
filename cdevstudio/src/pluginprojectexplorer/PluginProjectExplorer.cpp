#include "PluginProjectExplorer.h"

PluginProjectExplorer::PluginProjectExplorer()
{
	m_Platform = IPlatform::getInstance();
	
	Window *window = m_Platform->getWindow();
	PluginPage *pluginpage = new PluginPage(window->getSettingsDialog());
	window->getSettingsDialog()->addSettingsPage(pluginpage);
	
	m_ProjectExplorer = new ProjectExplorer(window);
	window->addDockWidget(Qt::LeftDockWidgetArea, m_ProjectExplorer);
	
	m_ActionProjectExplorer = new QAction(tr("Project Explorer"), window->getMenuBar());
	m_ActionProjectExplorer->setShortcut(Qt::Key_F9);
	m_ActionProjectExplorer->setCheckable(true);
	m_ActionProjectExplorer->setChecked(true);
	window->getMenuBar()->getMenu(tr("View"))->addAction(m_ActionProjectExplorer);
	
	connect(m_Platform->getProjectManager(), SIGNAL(projectOpened()), this, SLOT(projectOpen()));
	connect(m_Platform->getProjectManager(), SIGNAL(projectClosed()), this, SLOT(projectClose()));
	connect(m_ProjectExplorer, SIGNAL(fileClicked(QString)), this, SLOT(fileOpen(QString)));
	connect(m_ActionProjectExplorer, SIGNAL(triggered(bool)), this, SLOT(actionProjectExplorerTrigger()));
}

PluginProjectExplorer::~PluginProjectExplorer()
{
}

void PluginProjectExplorer::projectOpen()
{
	Project *project = m_Platform->getProjectManager()->getProject();
	m_ProjectExplorer->openView(project->getLocation());
}

void PluginProjectExplorer::projectClose()
{
	m_ProjectExplorer->clearView();
}

void PluginProjectExplorer::fileOpen(QString file)
{
	if(!file.isEmpty())
	{
		m_Platform->getProjectManager()->openFile(file);
	}
}

void PluginProjectExplorer::actionProjectExplorerTrigger()
{
	if(m_ActionProjectExplorer->isChecked())
	{
		m_ProjectExplorer->show();
	}
	else
	{
		m_ProjectExplorer->hide();
	}
}
