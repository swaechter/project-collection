#ifndef PLUGINPROJECT_H
#define PLUGINPROJECT_H

#include <QtWidgets/QAction>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QFileDialog>
#include <QtCore/QObject>

#include <IPlatform.h>
#include <plugin/IPlugin.h>
#include <ui/Window.h>

#include "PluginProjectExport.h"
#include "ProjectTemplate.h"
#include "PluginPage.h"
#include "CreateProjectDialog.h"

class PLUGINPROJECT_EXPORT PluginProject : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin" FILE "PluginProject.json")
	
public:
	PluginProject();
	~PluginProject();
	
private:
	IPlatform *m_Platform;
	QAction *m_ActionCreateProject;
	QAction *m_ActionOpenProject;
	QAction *m_ActionCloseProject;
	QAction *m_ActionCreateFile;
	QAction *m_ActionOpenFile;
	QAction *m_ActionDeleteFile;
	QAction *m_ActionRenameFile;
	QAction *m_ActionSaveFile;
	QAction *m_ActionCloseFile;
	
private slots:
	void actionCreateProjectTrigger();
	void actionOpenProjectTrigger();
	void actionCloseProjectTrigger();
	void actionCreateFileTrigger();
	void actionOpenFileTrigger();
	void actionDeleteFileTrigger();
	void actionRenameFileTrigger();
	void actionSaveFileTrigger();
	void actionCloseFileTrigger();
};

#endif // PLUGINPROJECT_H
