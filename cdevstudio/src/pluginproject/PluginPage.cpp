#include "PluginPage.h"

PluginPage::PluginPage(QWidget *parent) : SettingsPage(parent)
{
	QTextEdit *textedit = new QTextEdit(this);
	textedit->setText("Projects");
	textedit->setReadOnly(true);
	
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(textedit);
	layout->setContentsMargins(0, 0, 0, 0);
}

QString PluginPage::getName()
{
	return QString(tr("Projects"));
}
