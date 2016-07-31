#ifndef SHAREDLIBRARY_H
#define SHAREDLIBRARY_H

#include <QtCore/QObject>

#include "SharedLibraryExport.h"

class SHAREDLIBRARY_API SharedLibrary : public QObject
{
public:
	SharedLibrary(QObject *parent);
	QString getLibraryInformation();
};

#endif // SHAREDLIBRARY_H
