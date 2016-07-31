#ifndef GENERALPAGE_H
#define GENERALPAGE_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QGridLayout>

#include <ui/SettingsPage.h>

class GeneralPage : public SettingsPage
{
	Q_OBJECT
	
public:
	GeneralPage(QWidget *parent);
	QString getName();
};

#endif // GENERALPAGE_H
