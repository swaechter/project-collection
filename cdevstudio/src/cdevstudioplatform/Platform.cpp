#include "Platform.h"

Platform::Platform(Window *window): IPlatform(window)
{
	m_PluginManager = new PluginManager(this);
	m_ProjectManager = new ProjectManager(this);
	m_Window = window;
}

PluginManager *Platform::getPluginManager()
{
	return m_PluginManager;
}

ProjectManager *Platform::getProjectManager()
{
	return m_ProjectManager;
}

Window *Platform::getWindow()
{
	return m_Window;
}
