#ifndef PLUGINEDITOR_H
#define PLUGINEDITOR_H

#include <QtCore/QObject>

#include <IPlatform.h>
#include <plugin/IPlugin.h>

#include "PluginEditorExport.h"
#include "PluginPage.h"

class PLUGINEDITOR_EXPORT PluginEditor : public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "ch.swaechter.cdevstudioplatform.IPlugin" FILE "PluginEditor.json")
	
public:
	PluginEditor();
	~PluginEditor();
	
private:
	IPlatform *m_Platform;
	
private slots:
	void openFile(QString file);
	void reopenFile(QString file);
	void closeFile(QString file);
	void closeFileRequest(QString file);
};

#endif // PLUGINEDITOR_H
