#include "StaticLibrary.h"

StaticLibrary::StaticLibrary(QObject *parent) : QObject(parent)
{

}

QString StaticLibrary::getLibraryInformation()
{
	return QString("StaticLibrary v0.1.0 by Simon Waechter - GNU GPL v3");
}
