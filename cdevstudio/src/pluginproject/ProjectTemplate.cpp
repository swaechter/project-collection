#include "ProjectTemplate.h"

ProjectTemplate::ProjectTemplate(QString name, QString description, QStringList files)
{
	m_Name = name;
	m_Description = description;
	m_Files = files;
}

QString ProjectTemplate::getName()
{
	return m_Name;
}

QString ProjectTemplate::getDescription()
{
	return m_Description;
}

QStringList ProjectTemplate::getFiles()
{
	return m_Files;
}
