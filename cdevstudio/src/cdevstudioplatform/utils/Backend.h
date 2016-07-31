#ifndef BACKEND_H
#define BACKEND_H

#include <QtCore/QStringList>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QTextStream>

#include <PlatformExport.h>

namespace Backend
{
	CDEVSTUDIOPLATFORM_EXPORT bool doesPathExist(QString path);
	CDEVSTUDIOPLATFORM_EXPORT bool isPathADirectory(QString path);
	CDEVSTUDIOPLATFORM_EXPORT bool createDirectory(QString directorypath);
	CDEVSTUDIOPLATFORM_EXPORT bool createFile(QString filepath);
	CDEVSTUDIOPLATFORM_EXPORT bool deleteFile(QString filepath);
	CDEVSTUDIOPLATFORM_EXPORT bool renameFile(QString filepath, QString newfilename);
	CDEVSTUDIOPLATFORM_EXPORT bool writeFile(QString filepath, QString text);
	CDEVSTUDIOPLATFORM_EXPORT QString readFile(QString filepath);
	CDEVSTUDIOPLATFORM_EXPORT QString getDirectoryOfFile(QString filepath);
	CDEVSTUDIOPLATFORM_EXPORT QString getNameOfFile(QString filepath);
	CDEVSTUDIOPLATFORM_EXPORT QStringList getFilesInDirectory(QString directorypath);
}

#endif // BACKEND_H
