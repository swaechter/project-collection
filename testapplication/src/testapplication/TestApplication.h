#ifndef TESTAPPLICATION_H
#define TESTAPPLICATION_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QMenu>
#include <QtWidgets/QAction>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QGridLayout>
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <staticlibrary/StaticLibrary.h>
#include <sharedlibrary/SharedLibrary.h>

#include "ui_TestApplication.h"
#include "DialogResourceText.h"
#include "DialogUi.h"

class TestApplication : public QMainWindow, public Ui::TestApplication
{
	Q_OBJECT
	
public:
	TestApplication();
	
private slots:
	void initWindow();
	void initConnections();
	void initTextEdit();
	void actionResourceTextTrigger();
	void actionDialogUiTrigger();
	void actionStaticLibraryTrigger();
	void actionSharedLibraryTrigger();
	void actionExitTrigger();
	void actionHelpTrigger();
	void actionAboutTrigger();
};

#endif // TESTAPPLICATION_H
