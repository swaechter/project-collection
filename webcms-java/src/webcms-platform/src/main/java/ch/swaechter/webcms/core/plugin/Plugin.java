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

import ch.swaechter.webcms.core.modules.mvc.controller.Controller;
import ch.swaechter.webcms.core.settings.Settings;

/**
 * This class represents a plugin that can provide additional functionality.
 *
 * @author Simon Wächter
 */
public interface Plugin
{
	/**
	 * Get the system plugin name.
	 */
	public String getSystemName();

	/**
	 * Get the displayable plugin name.
	 */
	public String getDisplayableName();

	/**
	 * Get all initialized controllers.
	 *
	 * @param pluginmanager Plugin manager
	 * @param settings Settings
	 * @return Initialized controllers
	 */
	public ArrayList<Controller> getControllers(PluginManager pluginmanager, Settings settings);
}
