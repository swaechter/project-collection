#include "SharedLibrary.h"

SharedLibrary::SharedLibrary(QObject *parent) : QObject(parent)
{

}

QString SharedLibrary::getLibraryInformation()
{
	return QString("SharedLibrary v0.1.0 by Simon Waechter - GNU GPL v3");
}
