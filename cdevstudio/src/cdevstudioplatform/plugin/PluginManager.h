#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QDir>
#include <QtCore/QPluginLoader>
#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>

#include <PlatformExport.h>
#include <plugin/PluginContainer.h>
#include <utils/Backend.h>

class CDEVSTUDIOPLATFORM_EXPORT PluginManager : public QObject
{
	Q_OBJECT
	
public:
	PluginManager(QObject *parent);
	QList<PluginContainer *> getPluginContainers();
	
private:
	QList<PluginContainer *> m_PluginContainers;
};

#endif // PLUGINMANAGER_H
