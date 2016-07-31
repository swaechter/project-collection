#ifndef MENUBAR_H
#define MENUBAR_H

#include <QtWidgets/QMenuBar>

#include <PlatformExport.h>

class CDEVSTUDIOPLATFORM_EXPORT MenuBar : public QMenuBar
{
	Q_OBJECT
	
public:
	MenuBar(QWidget *parent);
	QMenu *getMenu(QString name);
};

#endif // MENUBAR_H
