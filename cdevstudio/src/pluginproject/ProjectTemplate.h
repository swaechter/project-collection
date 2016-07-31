#ifndef PROJECTTEMPLATE_H
#define PROJECTTEMPLATE_H

#include <QtCore/QString>
#include <QtCore/QStringList>

#include "PluginProjectExport.h"

class PLUGINPROJECT_EXPORT ProjectTemplate
{
public:
	ProjectTemplate(QString name, QString description, QStringList files);
	QString getName();
	QString getDescription();
	QStringList getFiles();
	
private:
	QString m_Name;
	QString m_Description;
	QStringList m_Files;
};

#endif // PROJECTTEMPLATE_H
