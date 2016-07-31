#ifndef DIALOGUI_H
#define DIALOGUI_H

#include <QtWidgets/QDialog>
#include <ui_DialogUi.h>

class DialogUi : public QDialog, Ui::DialogUi
{
	Q_OBJECT
	
public:
	DialogUi(QWidget *parent);
};

#endif // DIALOGUI_H
