#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_AboutDialog.h"

class AboutDialog : public QDialog, private Ui::AboutDialog
{
	Q_OBJECT
	
public:
	AboutDialog(QWidget *parent, QString abouttext, QString licensetext, QString thankstotext);
};

#endif // ABOUTDIALOG_H
