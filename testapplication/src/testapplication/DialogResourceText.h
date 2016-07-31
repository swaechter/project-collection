#ifndef DIALOGRESOURCETEXT_H
#define DIALOGRESOURCETEXT_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QGridLayout>

class DialogResourceText : public QDialog
{
	Q_OBJECT
	
public:
	DialogResourceText(QString text, QWidget *parent);
};

#endif // DIALOGRESOURCETEXT_H
