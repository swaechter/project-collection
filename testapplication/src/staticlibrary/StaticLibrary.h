#ifndef STATICLIBRARY_H
#define STATICLIBRARY_H

#include <QtCore/QObject>

class StaticLibrary : public QObject
{
	Q_OBJECT
	
public:
	StaticLibrary(QObject *parent);
	QString getLibraryInformation();
};

#endif // STATICLIBRARY_H
