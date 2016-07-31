# WebCMS [![Build Status](https://travis-ci.org/swaechter/webcms.svg)](https://travis-ci.org/swaechter/webcms)

## Introduction

WebCMS is a content management system (CMS) based on Java that allows a user to create, edit and delete his own content.

## Installation

The CMS runs as servlet container in any available application server - for example Tomcat.

### Download the project

	git clone https://github.com/swaechter/webcms

### Start Eclipse and import the project

	Start Eclipse
	Click "File" / "Import..." / "Existing Maven Projects" and select the project directory

### Edit the configuration

	Edit the system configuration in src/webcms-application/src/main/java/ch/swaechter/webcms/application/Application.java

### Export the WAR file

	Click "File" / "Export..." / "WAR file", select the webcms-application project and choose a destination location

### Install the WAR file

	Drop the WAR file inside the webapp directory of your application server
	Restart the server or add the WAR file to the enabled webapps list

## License

WebCMS is licensed under the GNU GPL v3 or later:

	WebCMS - A content management system (CMS) based on Java
	Copyright (C) 2015 Simon Wächter (waechter.simon@gmail.com)
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see http://www.gnu.org/licenses/

## Contact

For questions or help feel free to contact me via email (waechter.simon@gmail.com).
