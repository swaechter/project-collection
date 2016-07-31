#include <QtWidgets/QApplication>

#include "TestApplication.h"

int main(int argc, char **argv)
{
	QApplication application(argc, argv);
	
	TestApplication testapplication;
	testapplication.show();
	
	return application.exec();
}
