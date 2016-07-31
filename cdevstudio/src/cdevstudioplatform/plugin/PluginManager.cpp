#include "PluginManager.h"

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_WIN
	QCoreApplication::addLibraryPath("C:/Program Files/cdevstudio-workspace/bin");
#else
	QCoreApplication::addLibraryPath("/usr/lib");
	QCoreApplication::addLibraryPath("/usr/lib64");
#endif
}

QList<PluginContainer *> PluginManager::getPluginContainers()
{
	if(m_PluginContainers.count() == 0)
	{
		foreach(QString path, QCoreApplication::libraryPaths())
		{
			foreach(QString filename, Backend::getFilesInDirectory(path))
			{
				QString file = path + QString("/") + filename;
				if(QLibrary::isLibrary(file))
				{
					QPluginLoader loader(file, this);
					IPlugin *plugin = qobject_cast<IPlugin *>(loader.instance());
					if(plugin)
					{
						bool existing = false;
						foreach(PluginContainer *container, m_PluginContainers)
						{
							if(container->getPlugin() == plugin)
							{
								existing = true;
							}
						}
						
						if(!existing)
						{
							QString name = loader.metaData().value("MetaData").toObject().value("name").toString();
							QString description = loader.metaData().value("MetaData").toObject().value("description").toString();
							PluginContainer *container = new PluginContainer(this, plugin, name, description);
							m_PluginContainers.append(container);
						}
					}
				}
			}
		}
	}
	return m_PluginContainers;
}
