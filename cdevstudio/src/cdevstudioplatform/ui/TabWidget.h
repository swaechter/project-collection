#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtCore/QList>

#include <PlatformExport.h>

class CDEVSTUDIOPLATFORM_EXPORT TabWidget : public QTabWidget
{
	Q_OBJECT
	
public:
	TabWidget(QWidget *parent);
	void addTextEdit(QTextEdit *textedit, QString title);
	void removeTextEdit(QString title);
	QTextEdit *getTextEdit(QString title);
	QList<QTextEdit *> getTextEdits();
	
private slots:
	void closeTab(int index);
	
signals:
	void closeTabRequested(QString name);
};

#endif // TABWIDGET_H
