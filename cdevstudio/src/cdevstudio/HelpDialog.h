#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_HelpDialog.h"

class HelpDialog : public QDialog, private Ui::HelpDialog
{
	Q_OBJECT
	
public:
	HelpDialog(QWidget *parent, QString helptext);
};

#endif // HELPDIALOG_H
