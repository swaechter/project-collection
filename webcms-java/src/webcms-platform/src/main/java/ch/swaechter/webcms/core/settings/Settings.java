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

package ch.swaechter.webcms.core.settings;

/**
 * This class contains all important CMS information.
 *
 * @author Simon Wächter
 */
public class Settings
{
	/**
	 * Default route that will be used in case of a problem
	 */
	private final String defaultroute;

	/**
	 * URL prefix for all static files.
	 */
	private final String resourceprefix;

	/**
	 * Constructor with the default route that will be used in case of an problem.
	 *
	 * @param defaultroute Default route
	 * @param resourceprefix URL prefix for all static files
	 */
	public Settings(String defaultroute, String resourceprefix)
	{
		this.defaultroute = defaultroute;
		this.resourceprefix = resourceprefix;
	}

	/**
	 * Get the default route.
	 *
	 * @return Default route
	 */
	public String getDefaultRoute()
	{
		return defaultroute;
	}

	/**
	 * Get the URL prefix for all static files.
	 *
	 * @return URL prefix
	 */
	public String getResourcePrefix()
	{
		return resourceprefix;
	}
}
