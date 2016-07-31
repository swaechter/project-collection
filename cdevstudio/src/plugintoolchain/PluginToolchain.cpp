#include "PluginToolchain.h"

PluginToolchain::PluginToolchain()
{
	m_Platform = IPlatform::getInstance();
	
	Window *window = m_Platform->getWindow();
	PluginPage *pluginpage = new PluginPage(window->getSettingsDialog());
	window->getSettingsDialog()->addSettingsPage(pluginpage);
	
	m_ActionBuild = new QAction(tr("Build"), window->getMenuBar());
	m_ActionRun = new QAction(tr("Run"), window->getMenuBar());
	m_ActionBuildAndRun = new QAction(tr("Build and Run"), window->getMenuBar());
	
	m_ActionBuild->setShortcut(Qt::Key_F5);
	m_ActionRun->setShortcut(Qt::Key_F6);
	m_ActionBuildAndRun->setShortcut(Qt::Key_F7);
	
	window->getMenuBar()->getMenu(tr("Code"))->addAction(m_ActionBuild);
	window->getMenuBar()->getMenu(tr("Code"))->addAction(m_ActionRun);
	window->getMenuBar()->getMenu(tr("Code"))->addAction(m_ActionBuildAndRun);
	
	connect(m_ActionBuild, SIGNAL(triggered(bool)), this, SLOT(actionBuildTrigger()));
	connect(m_ActionRun, SIGNAL(triggered(bool)), this, SLOT(actionRunTrigger()));
	connect(m_ActionBuildAndRun, SIGNAL(triggered(bool)), this, SLOT(actionBuldAndRunTrigger()));
}

PluginToolchain::~PluginToolchain()
{
}

void PluginToolchain::actionBuildTrigger()
{
	QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Feature not implemented yet."));
}

void PluginToolchain::actionRunTrigger()
{
	QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Feature not implemented yet."));
}

void PluginToolchain::actionBuldAndRunTrigger()
{
	QMessageBox::information(m_Platform->getWindow(), tr("Information"), tr("Feature not implemented yet."));
}
