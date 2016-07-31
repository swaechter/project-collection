#include <QtWidgets/QApplication>

#include "CDevStudio.h"

int main(int argc, char **argv)
{
	QApplication application(argc, argv);
	
	CDevStudio cdevstudio;
	cdevstudio.show();
	
	return application.exec();
}
