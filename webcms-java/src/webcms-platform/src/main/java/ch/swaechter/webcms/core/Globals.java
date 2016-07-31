/**
 * WebCMS - A content management system (CMS) based on Java
 * Copyright (C) 2015 Simon Wächter (waechter.simon@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 */

package ch.swaechter.webcms.core;

/**
 * This class contains several variables that are used internally.
 *
 * @author Simon Wächter
 */
public class Globals
{
	/**
	 * Directory separator for file and directory paths.
	 */
	public static final String DIRECTORY_SEPARATOR = "/";

	/**
	 *  Directory that contains all static resources.
	 */
	public static final String WEBAPP_WEBINF_DIRECTORY = "/WEB-INF";

	/**
	 * File that is used as fallback site in case of an internal error.
	 */
	public static final String WEBAPP_FALLBACK_VIEW_FILE = "index.ftl";

	/**
	 * File extension of all static HTML files.
	 */
	public static final String WEBAPP_VIEW_EXTENSION = ".ftl";

	/**
	 * Suffix for controller class names.
	 */
	public static final String CONTROLLER_CLASS_SUFFIX = "controller";
}
