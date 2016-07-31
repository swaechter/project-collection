#include "Window.h"

Window::Window() : QMainWindow()
{
	m_Menubar = new MenuBar(this);
	m_TabWidget = new TabWidget(this);
	m_Settings = new Settings(this);
	setMenuBar(m_Menubar);
	setCentralWidget(m_TabWidget);
}

MenuBar *Window::getMenuBar()
{
	return m_Menubar;
}

TabWidget *Window::getTabWidget()
{
	return m_TabWidget;
}

Settings *Window::getSettingsDialog()
{
	return m_Settings;
}
