# GIBM Notebook-Shop

## Introduction

A Joomla! template for the GIBM Notebook-Shop.

## Build the template

	./create_template.sh

## Installation

### Install Joomla!

	Install a clean Joomla! instance

### Change the plugins

	Go to your Joomla! administration panel
	Navigate to 'Extensions' / 'Module Manager'
	Disable the 'Breadcrumbs' plugin
	Disable the 'Login Form' plugin

	Navigate to 'Extensions' / 'Module Manager'
	Click the 'Main Menu' plugin
	Enable 'Show Sub-menu Items'

### Change the site layout

	Go to your Joomla! administration panel
	Navigate to 'Content' / 'Article Manager'
	Click 'Options' on the right side
	Hide 'Show Title'
	Hide 'Linked Titles'
	Hide 'Show Intro Text'
	Hide 'Show Category'
	Hide 'Link Category'
	Hide 'Show Author'
	Hide 'Show Publish Date'
	Hide 'Show Navigation'
	Hide 'Show Title with Read More'
	Hide 'Show Tags'
	Hide 'Show Icons'
	Hide 'Show Print Icon'
	Hide 'Show Email Icon'
	Hide 'Show Hits'

	Navigate to 'Menu' / 'Menu Manager'
	Click 'Options' on the right side
	Disable 'Show Page Heading'

### Create a new article and menu item

	Go to your Joomla! administration panel
	Navigate to 'Content' / 'Article Manager'
	Create a new article

	Navigate to 'Menu' / 'Menu Manager'
	Create a new menu
	Select 'Article' / 'Single Article' as 'Menu Item Type'
	Select the article as 'Select Article'
	Change the 'Parent Item' value of the menu on the right side if necessary
	Switch to the 'Page Display' tab and set 'Show Page Heading' to 'No' 

### Install the template

	Go to your Joomla! administration panel
	Navigate to 'Extensions' / 'Extension Manager'
	Select the template via file chooser
	Click 'Upload & Install'

### Select the template as active template

	Go to your Joomla! administration panel
	Navigate to 'Extensions' / 'Template Manager'
	Select the 'GIBM Notebook-Shop' as default 'Site' template
