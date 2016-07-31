#include "HelpDialog.h"

HelpDialog::HelpDialog(QWidget *parent, QString helptext) : QDialog(parent)
{
	setupUi(this);
	
	textEditHelp->setText(helptext);
	
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}
