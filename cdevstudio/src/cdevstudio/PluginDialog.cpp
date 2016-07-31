#include "PluginDialog.h"

PluginDialog::PluginDialog(QWidget *parent, QList<PluginContainer *> plugincontainers) : QDialog(parent)
{
	setupUi(this);
	
	tableWidgetPlugins->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	
	foreach(PluginContainer *plugincontainer, plugincontainers)
	{
		int rows = tableWidgetPlugins->rowCount();
		tableWidgetPlugins->setRowCount(rows + 1);
		tableWidgetPlugins->setItem(rows, 0, new QTableWidgetItem(plugincontainer->getName()));
		tableWidgetPlugins->setItem(rows, 1, new QTableWidgetItem(plugincontainer->getDescription()));
	}
	
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}
