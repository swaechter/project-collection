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

package ch.swaechter.webcms.core.plugin;

import java.util.ArrayList;

/**
 * This class contains the plugin manager who manages all loaded plugins.
 *
 * @author Simon Wächter
 */
public class PluginManager
{
	/**
	 * List with all loaded plugins.
	 */
	private final ArrayList<Plugin> plugins;

	/**
	 * Constructor with the plugins that will be used.
	 *
	 * @param plugins All plugins
	 */
	public PluginManager(ArrayList<Plugin> plugins)
	{
		this.plugins = plugins;
	}

	/**
	 * Get all loaded plugins.
	 *
	 * @return List with all loaded plugins
	 */
	public ArrayList<Plugin> getPlugins()
	{
		return plugins;
	}
}
