#include "TabWidget.h"

TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent)
{
	setTabsClosable(true);
	
	connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
}

void TabWidget::addTextEdit(QTextEdit *textedit, QString title)
{
	addTab(textedit, title);
}

void TabWidget::removeTextEdit(QString title)
{
	for(int i = 0; i < count(); i++)
	{
		if(title.compare(tabText(i)) == 0)
		{
			QWidget *tabwidget = widget(i);
			if(tabwidget)
			{
				removeTab(i);
				delete tabwidget;
			}
		}
	}
}

QTextEdit *TabWidget::getTextEdit(QString title)
{
	for(int i = 0; i < count(); i++)
	{
		if(title.compare(tabText(i)) == 0)
		{
			return qobject_cast<QTextEdit *>(widget(i));
		}
	}
	return nullptr;
}

QList<QTextEdit *> TabWidget::getTextEdits()
{
	QList<QTextEdit *> textedits;
	for(int i = 0; i < count(); i++)
	{
		QTextEdit *textedit = qobject_cast<QTextEdit *>(widget(i));
		if(textedit)
		{
			textedits.append(textedit);
		}
	}
	return textedits;
}

void TabWidget::closeTab(int index)
{
	if(index >= 0)
	{
		emit closeTabRequested(tabText(index));
	}
}
