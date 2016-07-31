#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QString>
#include <QtCore/QStringList>

#include <PlatformExport.h>

class CDEVSTUDIOPLATFORM_EXPORT Project
{
	friend class ProjectManager;
	
public:
	QString getName();
	QString getLocation();
	QString getProjectFile();
	QStringList getFiles();
	
private:
	void setName(QString name);
	void setLocation(QString location);
	void setFiles(QStringList files);
	void addFile(QString file);
	void removeFile(QString file);
	
	QString m_Name;
	QString m_Location;
	QStringList m_Files;
};

#endif // PROJECT_H
