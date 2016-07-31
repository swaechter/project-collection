#include "DialogResourceText.h"

DialogResourceText::DialogResourceText(QString text, QWidget *parent): QDialog(parent)
{
	setWindowTitle(tr("Resource Dialog"));
	
	QDialogButtonBox *dialogbuttonbox = new QDialogButtonBox(this);
	dialogbuttonbox->setOrientation(Qt::Horizontal);
	dialogbuttonbox->setStandardButtons(QDialogButtonBox::Ok);

	QTextEdit *textedit = new QTextEdit(this);
	textedit->setAcceptRichText(true);
	textedit->setText(text);
	textedit->setReadOnly(true);

	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(textedit);
	layout->addWidget(dialogbuttonbox);

	connect(dialogbuttonbox, SIGNAL(accepted()), this, SLOT(accept()));
}
