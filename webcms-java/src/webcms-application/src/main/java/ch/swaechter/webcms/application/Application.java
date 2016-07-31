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

package ch.swaechter.webcms.application;

import java.util.ArrayList;
import java.util.Arrays;

import ch.swaechter.webcms.adminplugin.AdminPlugin;
import ch.swaechter.webcms.core.Servlet;
import ch.swaechter.webcms.core.plugin.Plugin;
import ch.swaechter.webcms.core.settings.Settings;
import ch.swaechter.webcms.textplugin.TextPlugin;

/**
 * This class represents the servlet configuration.
 *
 * @author Simon Wächter
 */
public class Application extends Servlet
{
	/**
	 * Generated serialization ID.
	 */
	private final static long serialVersionUID = 1L;

	/**
	 * Constructor that passes the plugins and the configuration to the servlet.
	 */
	public Application()
	{
		super(getPlugins(), getSettings());
	}

	/**
	 * Get all plugins.
	 *
	 * @return Plugins
	 */
	public static ArrayList<Plugin> getPlugins()
	{
		return new ArrayList<>(Arrays.asList(new AdminPlugin(), new TextPlugin()));
	}

	/**
	 * Get the settings.
	 *
	 * @return Settings
	 */
	public static Settings getSettings()
	{
		return new Settings("/text/index", "static");
	}
}
