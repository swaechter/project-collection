#ifndef PLUGINCONTAINER_H
#define PLUGINCONTAINER_H

#include <QtCore/QObject>

#include <PlatformExport.h>
#include <plugin/IPlugin.h>

class CDEVSTUDIOPLATFORM_EXPORT PluginContainer : public QObject
{
	Q_OBJECT
	
public:
	PluginContainer(QObject *parent, IPlugin *plugin, QString name, QString description);
	IPlugin *getPlugin();
	QString getName();
	QString getDescription();
	
private:
	IPlugin *m_Plugin;
	QString m_Name;
	QString m_Description;
};

#endif // PLUGINCONTAINER_H
