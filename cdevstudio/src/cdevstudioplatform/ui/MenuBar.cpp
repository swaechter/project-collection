#include "MenuBar.h"

MenuBar::MenuBar(QWidget *parent) : QMenuBar(parent)
{
}

QMenu *MenuBar::getMenu(QString name)
{
	QList<QMenu *> menus = findChildren<QMenu *>();
	foreach(QMenu *menu, menus)
	{
		if(name.compare(menu->title()) == 0)
		{
			return menu;
		}
	}
	return nullptr;
}
