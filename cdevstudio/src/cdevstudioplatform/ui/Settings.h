#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QGridLayout>

#include <PlatformExport.h>
#include <ui/SettingsPage.h>

class CDEVSTUDIOPLATFORM_EXPORT Settings : public QDialog
{
	Q_OBJECT
	
public:
	Settings(QWidget *parent);
	void addSettingsPage(SettingsPage *settingspage);
	
private:
	QListWidget *m_ListWidget;
	QStackedWidget *m_StackedWidget;
	QList<SettingsPage *> m_SettingsPages;
	
private slots:
	void changePage(QListWidgetItem *currentitem, QListWidgetItem *olditem);
	void acceptTrigger();
	void rejectTrigger();
};

#endif // SETTINGS_H
