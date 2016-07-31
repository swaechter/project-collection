#include "PluginEditor.h"

PluginEditor::PluginEditor()
{
	m_Platform = IPlatform::getInstance();
	
	Window *window = m_Platform->getWindow();
	PluginPage *pluginpage = new PluginPage(window->getSettingsDialog());
	window->getSettingsDialog()->addSettingsPage(pluginpage);
	
	connect(m_Platform->getProjectManager(), SIGNAL(fileOpened(QString)), this, SLOT(openFile(QString)));
	connect(m_Platform->getProjectManager(), SIGNAL(fileReopened(QString)), this, SLOT(reopenFile(QString)));
	connect(m_Platform->getProjectManager(), SIGNAL(fileClosed(QString)), this, SLOT(closeFile(QString)));
	connect(window->getTabWidget(), SIGNAL(closeTabRequested(QString)), this, SLOT(closeFileRequest(QString)));
}

PluginEditor::~PluginEditor()
{
}

void PluginEditor::openFile(QString file)
{
	Project *project = m_Platform->getProjectManager()->getProject();
	if(project)
	{
		if(m_Platform->getProjectManager()->getProject()->getFiles().contains(file))
		{
			TabWidget *tabwidget = m_Platform->getWindow()->getTabWidget();
			QTextEdit *textedit = new QTextEdit(tabwidget);
			textedit->setText(Backend::readFile(project->getLocation() + file));
			tabwidget->addTab(textedit, file);
			tabwidget->setCurrentWidget(textedit);
		}
	}
}

void PluginEditor::reopenFile(QString file)
{
	Project *project = m_Platform->getProjectManager()->getProject();
	if(project)
	{
		if(m_Platform->getProjectManager()->getProject()->getFiles().contains(file))
		{
			TabWidget *tabwidget = m_Platform->getWindow()->getTabWidget();
			QTextEdit *textedit = tabwidget->getTextEdit(file);
			if(textedit)
			{
				tabwidget->setCurrentWidget(textedit);
			}
		}
	}
}

void PluginEditor::closeFile(QString file)
{
	TabWidget *tabwidget = m_Platform->getWindow()->getTabWidget();
	for(int i = 0; i < tabwidget->count(); i++)
	{
		if(file.compare(tabwidget->tabText(i)) == 0)
		{
			QWidget *widget = tabwidget->widget(i);
			tabwidget->removeTab(i);
			delete widget;
		}
	}
}

void PluginEditor::closeFileRequest(QString file)
{
	TabWidget *tabwidget = m_Platform->getWindow()->getTabWidget();
	for(int i = 0; i < tabwidget->count(); i++)
	{
		if(file.compare(tabwidget->tabText(i)) == 0)
		{
			ProjectManager * projectmanager = m_Platform->getProjectManager();
			if(projectmanager->getProject())
			{
				projectmanager->closeFile(file);
			}
			break;
		}
	}
}
