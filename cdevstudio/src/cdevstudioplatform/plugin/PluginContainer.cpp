#include "PluginContainer.h"

PluginContainer::PluginContainer(QObject *parent, IPlugin *plugin, QString name, QString description) : QObject(parent)
{
	m_Plugin = plugin;
	m_Name = name;
	m_Description = description;
}

IPlugin *PluginContainer::getPlugin()
{
	return m_Plugin;
}

QString PluginContainer::getName()
{
	return m_Name;
}

QString PluginContainer::getDescription()
{
	return m_Description;
}
