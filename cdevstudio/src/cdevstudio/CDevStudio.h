#ifndef CDEVSTUDIO_H
#define CDEVSTUDIO_H

#include <Platform.h>
#include <ui/Window.h>
#include <ui/Settings.h>
#include <utils/Backend.h>

#include "PluginDialog.h"
#include "HelpDialog.h"
#include "AboutDialog.h"
#include "GeneralPage.h"

class CDevStudio : public Window
{
	Q_OBJECT
	
public:
	CDevStudio();
	~CDevStudio();
	
private:
	void initPlatform();
	void preinitWindow();
	void initSettings();
	void loadPlugins();
	void initWindow();
	
	Platform *m_Platform;
	QAction *m_ActionExit;
	QAction *m_ActionSettings;
	QAction *m_ActionPlugins;
	QAction *m_ActionHelp;
	QAction *m_ActionAbout;
	
private slots:
	void actionExitTrigger();
	void actionSettingsTrigger();
	void actionPluginsTrigger();
	void actionHelpTrigger();
	void actionAboutTrigger();
};

#endif // CDEVSTUDIO_H
