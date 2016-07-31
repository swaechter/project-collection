#include "TestApplication.h"

TestApplication::TestApplication() : QMainWindow()
{
	initWindow();
	initConnections();
	initTextEdit();
}

void TestApplication::initWindow()
{
	setupUi(this);
	setWindowIcon(QIcon(":/data/icon/application.ico"));
}

void TestApplication::initConnections()
{
	connect(actionResourceText, SIGNAL(triggered(bool)), this, SLOT(actionResourceTextTrigger()));
	connect(actionDialogUi, SIGNAL(triggered(bool)), this, SLOT(actionDialogUiTrigger()));
	connect(actionStaticLibrary, SIGNAL(triggered(bool)), this, SLOT(actionStaticLibraryTrigger()));
	connect(actionSharedLibrary, SIGNAL(triggered(bool)), this, SLOT(actionSharedLibraryTrigger()));
	connect(actionExit, SIGNAL(triggered(bool)), this, SLOT(actionExitTrigger()));
	connect(actionHelp, SIGNAL(triggered(bool)), this, SLOT(actionHelpTrigger()));
	connect(actionAbout, SIGNAL(triggered(bool)), this, SLOT(actionAboutTrigger()));
}

void TestApplication::initTextEdit()
{
	textEdit->setText(tr("Welcome to testapplication stranger! Here you can see and test some typical components of a Qt5 application"));
}

void TestApplication::actionResourceTextTrigger()
{
	QFile file(":/data/text/index.html");
	if(file.open(QFile::ReadOnly | QFile::Text))
	{
		QTextStream stream(&file);
		QString text = stream.readAll();
		DialogResourceText *dialog = new DialogResourceText(text, this);
		dialog->exec();
	}
	file.close();	
}

void TestApplication::actionDialogUiTrigger()
{
	DialogUi *dialog = new DialogUi(this);
	if(dialog->exec() == QDialog::Accepted)
	{
		// Maybe save your settings
	}
}

void TestApplication::actionStaticLibraryTrigger()
{
	StaticLibrary library(this);
	QMessageBox::information(this, tr("Static Library"), library.getLibraryInformation());
}

void TestApplication::actionSharedLibraryTrigger()
{
	SharedLibrary library(this);
	QMessageBox::information(this, tr("Shared Library"), library.getLibraryInformation());
}

void TestApplication::actionExitTrigger()
{
	exit(EXIT_SUCCESS);
}

void TestApplication::actionHelpTrigger()
{
	QMessageBox::information(this, tr("Help"), tr("This application is based on the Qt5 framework and uses CMake as build system. It aims to be a cookbook"));
}

void TestApplication::actionAboutTrigger()
{
	QMessageBox::about(this, tr("About"), tr("Name: testapplication\nAuthor: Simon Waechter\nLink: https://github.com/swaechter/testapplication"));
}
