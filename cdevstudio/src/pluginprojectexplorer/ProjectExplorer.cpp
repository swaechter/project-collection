#include "ProjectExplorer.h"

ProjectExplorer::ProjectExplorer(QWidget *parent) : QDockWidget(parent)
{
	m_TreeView = new QTreeView(this);
	m_TreeView->header()->hide();
	
	m_FileSystemModel = new QFileSystemModel(this);
	
	setWindowTitle(tr("ProjectExplorer"));
	setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	setWidget(m_TreeView);
	
	connect(m_TreeView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(fileClick()));
}

void ProjectExplorer::openView(QString directory)
{
	m_FileSystemModel->setRootPath(directory);
	m_TreeView->setModel(m_FileSystemModel);
	m_TreeView->setRootIndex(m_FileSystemModel->index(directory));
	m_TreeView->hideColumn(1);
	m_TreeView->hideColumn(2);
	m_TreeView->hideColumn(3);
}

void ProjectExplorer::clearView()
{
	m_TreeView->setModel(nullptr);
}

void ProjectExplorer::fileClick()
{
	int row = -1;
	QString rootpath = m_FileSystemModel->rootPath() + QString("/");
	QModelIndexList indexlist = m_TreeView->selectionModel()->selectedIndexes();
	foreach(QModelIndex index, indexlist)
	{
		if(index.row() != row && index.column() == 0)
		{
			QFileInfo fileInfo = m_FileSystemModel->fileInfo(index);
			QString absoultepath = fileInfo.filePath();
			QString file = absoultepath.remove(rootpath);
			row = index.row();
			emit fileClicked(file);
		}
	}
}
