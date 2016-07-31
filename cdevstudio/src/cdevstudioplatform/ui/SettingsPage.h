#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QtWidgets/QWidget>

#include <PlatformExport.h>

class CDEVSTUDIOPLATFORM_EXPORT SettingsPage : public QWidget
{
	Q_OBJECT
	
public:
	SettingsPage(QWidget *parent);
	virtual QString getName() = 0;
};

#endif // SETTINGSPAGE_H
