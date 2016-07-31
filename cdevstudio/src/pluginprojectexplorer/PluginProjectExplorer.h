#ifndef PLUGINPROJECTEXPLORER_H
#define PLUGINPROJECTEXPLORER_H

#include <QtWidgets/QAction>
#include <QtCore/QObject>

#include <IPlatform.h>
#include <plugin/IPlugin.h>
#include <project/Project.h>
#include <ui/Window.h>

#include "PluginProjectExplorerExport.h"
#include "ProjectExplorer.h"
#include "PluginPage.h"

class PLUGINPROJECTEXPLORER_EXPORT PluginProjectExplorer : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin" FILE "PluginProjectExplorer.json")
	
public:
	PluginProjectExplorer();
	~PluginProjectExplorer();
	
private:
	IPlatform *m_Platform;
	ProjectExplorer *m_ProjectExplorer;
	QAction *m_ActionProjectExplorer;
	
private slots:
	void projectOpen();
	void projectClose();
	void fileOpen(QString file);
	void actionProjectExplorerTrigger();
};

#endif // PLUGINPROJECTEXPLORER_H
