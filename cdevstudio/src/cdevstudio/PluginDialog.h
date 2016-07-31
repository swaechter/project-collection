#ifndef PLUGINDIALOG_H
#define PLUGINDIALOG_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QHeaderView>
#include <QtCore/QList>

#include <plugin/PluginContainer.h>
#include <plugin/IPlugin.h>

#include "ui_PluginDialog.h"

class PluginDialog : public QDialog, private Ui::PluginDialog
{
	Q_OBJECT
	
public:
	PluginDialog(QWidget *parent, QList<PluginContainer *> plugincontainers);
};

#endif // PLUGINDIALOG_H
