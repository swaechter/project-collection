#ifndef PLUGINPAGE_H
#define PLUGINPAGE_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QGridLayout>

#include <ui/SettingsPage.h>

#include "PluginProjectExport.h"

class PLUGINPROJECT_EXPORT PluginPage : public SettingsPage
{
	Q_OBJECT
	
public:
	PluginPage(QWidget *parent);
	QString getName();
};

#endif // PLUGINPAGE_H
