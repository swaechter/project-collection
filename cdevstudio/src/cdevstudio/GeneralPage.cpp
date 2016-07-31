#include "GeneralPage.h"

GeneralPage::GeneralPage(QWidget *parent) : SettingsPage(parent)
{
	QTextEdit *textedit = new QTextEdit(this);
	textedit->setText("General");
	textedit->setReadOnly(true);
	
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(textedit);
	layout->setContentsMargins(0, 0, 0, 0);
}

QString GeneralPage::getName()
{
	return QString(tr("General"));
}
