#ifndef PROJECTEXPLORER_H
#define PROJECTEXPLORER_H

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QFileSystemModel>
#include <QtCore/QModelIndex>

#include "PluginProjectExplorerExport.h"

class PLUGINPROJECTEXPLORER_EXPORT ProjectExplorer : public QDockWidget
{
	Q_OBJECT
	
public:
	ProjectExplorer(QWidget *parent);
	void openView(QString directory);
	void clearView();
	
private slots:
	void fileClick();
	
private:
	QTreeView *m_TreeView;
	QFileSystemModel *m_FileSystemModel;
	
signals:
	void fileClicked(QString file);
};

#endif // PROJECTEXPLORER_H
