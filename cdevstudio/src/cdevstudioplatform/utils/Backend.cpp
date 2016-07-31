#include "Backend.h"

bool Backend::doesPathExist(QString path)
{
	return QFile(path).exists();
}

bool Backend::isPathADirectory(QString path)
{
	return QFileInfo(path).isDir();
}

bool Backend::createDirectory(QString directorypath)
{
	bool flag = false;
	QDir directory(directorypath);
	if(!directory.exists())
	{
		flag = directory.mkpath(directorypath);
	}
	return flag;
}

bool Backend::createFile(QString filepath)
{
	return writeFile(filepath, QString());
}

bool Backend::deleteFile(QString filepath)
{
	bool flag = false;
	QFile file(filepath);
	if(file.exists())
	{
		file.remove();
		flag = true;
	}
	return flag;
}

bool Backend::renameFile(QString filepath, QString newfilename)
{
	bool flag = false;
	QFile file(filepath);
	QFileInfo fileinfo(file);
	if(file.exists())
	{
		flag = file.rename(filepath , fileinfo.absolutePath() + QString("/") + newfilename);
	}
	return flag;
}

bool Backend::writeFile(QString filepath, QString text)
{
	bool flag = false;
	QFile file(filepath);
	if(file.open(QFile::WriteOnly))
	{
		QTextStream stream(&file);
		stream << text;
		file.close();
		flag = true;
	}
	return flag;
}

QString Backend::readFile(QString filepath)
{
	QString text;
	QFile file(filepath);
	if(file.open(QFile::ReadOnly))
	{
		QTextStream stream(&file);
		text = stream.readAll();
		file.close();
	}
	return text;
}

QString Backend::getDirectoryOfFile(QString filepath)
{
	return QFileInfo(filepath).absolutePath();
}

QString Backend::getNameOfFile(QString filepath)
{
	return QFileInfo(filepath).fileName();
}

QStringList Backend::getFilesInDirectory(QString directorypath)
{
	QStringList files;
	QDir directory(directorypath);
	if(directory.exists())
	{
		files = directory.entryList();
	}
	return files;
}
