#include "CDevStudio.h"

CDevStudio::CDevStudio() : Window()
{
	initPlatform();
	preinitWindow();
	initSettings();
	loadPlugins();
	initWindow();
}

CDevStudio::~CDevStudio()
{
	delete m_Platform;
}

void CDevStudio::initPlatform()
{
	m_Platform = new Platform(this);
}

void CDevStudio::preinitWindow()
{
	Window *window = m_Platform->getWindow();
	
	QMenu *menuproject = new QMenu(tr("Project"), window->getMenuBar());
	QMenu *menufile = new QMenu(tr("File"), window->getMenuBar());
	QMenu *menucode = new QMenu(tr("Code"), window->getMenuBar());
	QMenu *menuview = new QMenu(tr("View"), window->getMenuBar());
	QMenu *menusettings = new QMenu(tr("Settings"), window->getMenuBar());
	QMenu *menuhelp = new QMenu(tr("Help"), window->getMenuBar());
	
	window->getMenuBar()->addMenu(menuproject);
	window->getMenuBar()->addMenu(menufile);
	window->getMenuBar()->addMenu(menucode);
	window->getMenuBar()->addMenu(menuview);
	window->getMenuBar()->addMenu(menusettings);
	window->getMenuBar()->addMenu(menuhelp);
	
	m_ActionSettings = new QAction(tr("Settings"), window->getMenuBar());
	m_ActionPlugins = new QAction(tr("Plugins"), window->getMenuBar());
	m_ActionHelp = new QAction(tr("Help"), window->getMenuBar());
	m_ActionAbout = new QAction(tr("About"), window->getMenuBar());
	
	m_ActionSettings->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_S);
	m_ActionPlugins->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_P);
	m_ActionHelp->setShortcut(Qt::Key_F1);
	m_ActionAbout->setShortcut(Qt::Key_F2);
	
	window->getMenuBar()->getMenu(tr("Settings"))->addAction(m_ActionSettings);
	window->getMenuBar()->getMenu(tr("Settings"))->addAction(m_ActionPlugins);
	window->getMenuBar()->getMenu(tr("Help"))->addAction(m_ActionHelp);
	window->getMenuBar()->getMenu(tr("Help"))->addAction(m_ActionAbout);
	
	connect(m_ActionSettings, SIGNAL(triggered(bool)), this, SLOT(actionSettingsTrigger()));
	connect(m_ActionPlugins, SIGNAL(triggered(bool)), this, SLOT(actionPluginsTrigger()));
	connect(m_ActionHelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTrigger()));
	connect(m_ActionAbout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTrigger()));
}

void CDevStudio::initSettings()
{
	Settings *settings = m_Platform->getWindow()->getSettingsDialog();
	GeneralPage *generalpage = new GeneralPage(settings);
	settings->addSettingsPage(generalpage);
}

void CDevStudio::loadPlugins()
{
	m_Platform->getPluginManager()->getPluginContainers();
}

void CDevStudio::initWindow()
{
	Window *window = m_Platform->getWindow();
	window->setWindowTitle(tr("CDevStudio"));
	window->resize(1100, 700);
	
	m_ActionExit = new QAction(tr("Exit"), window->getMenuBar());
	
	m_ActionExit->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_X);
	
	window->getMenuBar()->getMenu(tr("Project"))->addSeparator();
	window->getMenuBar()->getMenu(tr("Project"))->addAction(m_ActionExit);
	
	connect(m_ActionExit, SIGNAL(triggered(bool)), this, SLOT(actionExitTrigger()));
}

void CDevStudio::actionExitTrigger()
{
	exit(EXIT_SUCCESS);
}

void CDevStudio::actionSettingsTrigger()
{
	Settings *settings = m_Platform->getWindow()->getSettingsDialog();
	if(settings->exec() == QDialog::Accepted)
	{
	}
}

void CDevStudio::actionPluginsTrigger()
{
	PluginDialog dialog(this, m_Platform->getPluginManager()->getPluginContainers());
	dialog.exec();
}

void CDevStudio::actionHelpTrigger()
{
	QString helptext = Backend::readFile(":/data/text_help.html");
	HelpDialog dialog(this, helptext);
	dialog.exec();
}

void CDevStudio::actionAboutTrigger()
{
	QString abouttext = Backend::readFile(":/data/text_about.html");
	QString licensetext = Backend::readFile(":/data/text_license.html");
	QString thankstotext = Backend::readFile(":/data/text_thanksto.html");
	AboutDialog dialog(this, abouttext, licensetext, thankstotext);
	dialog.exec();
}
