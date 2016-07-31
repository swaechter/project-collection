#include "Settings.h"

Settings::Settings(QWidget *parent)
{
	QDialogButtonBox *buttonbox = new QDialogButtonBox(this);
	buttonbox->setOrientation(Qt::Horizontal);
	buttonbox->setStandardButtons(QDialogButtonBox::Save | QDialogButtonBox::Cancel);
	
	m_ListWidget = new QListWidget(this);
	
	m_StackedWidget = new QStackedWidget(this);
	
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(m_ListWidget, 0, 0, 1, 1);
	layout->addWidget(m_StackedWidget, 0, 1, 1, 1);
	layout->addWidget(buttonbox, 1, 0, 1, 2);
	layout->setColumnStretch(0, 3);
	layout->setColumnStretch(1, 7);
	
	setMinimumSize(640, 480);
	setWindowTitle(tr("Settings"));
	
	connect(m_ListWidget, SIGNAL(currentItemChanged(QListWidgetItem *,QListWidgetItem *)), SLOT(changePage(QListWidgetItem *,QListWidgetItem *)));
	connect(buttonbox, SIGNAL(accepted()), this, SLOT(acceptTrigger()));
	connect(buttonbox, SIGNAL(rejected()), this, SLOT(rejectTrigger()));
}

void Settings::addSettingsPage(SettingsPage *settingspage)
{
	m_SettingsPages.append(settingspage);
	m_ListWidget->addItem(settingspage->getName());
	m_StackedWidget->addWidget(settingspage);
}

void Settings::changePage(QListWidgetItem *currentitem, QListWidgetItem *olditem)
{
	if(!currentitem)
	{
		currentitem = olditem;
	}
	m_StackedWidget->setCurrentIndex(m_ListWidget->row(currentitem));
}

void Settings::acceptTrigger()
{
	accept();
}

void Settings::rejectTrigger()
{
	reject();
}
