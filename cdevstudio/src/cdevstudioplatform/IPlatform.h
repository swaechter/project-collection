#ifndef IPLATFORM_H
#define IPLATFORM_H

#include <QtCore/QObject>

#include <PlatformExport.h>
#include <plugin/PluginManager.h>
#include <project/ProjectManager.h>
#include <ui/Window.h>

class CDEVSTUDIOPLATFORM_EXPORT IPlatform : public QObject
{
	Q_OBJECT
	
public:
	static IPlatform *getInstance();
	virtual PluginManager *getPluginManager() = 0;
	virtual ProjectManager *getProjectManager() = 0;
	virtual Window *getWindow() = 0;
	
protected:
	IPlatform(QObject *parent);
	static IPlatform *m_IPlatform;
};

#endif // IPLATFORM_H
