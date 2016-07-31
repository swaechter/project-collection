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

package ch.swaechter.webcms.textplugin;

import java.util.ArrayList;
import java.util.Arrays;

import ch.swaechter.webcms.core.modules.mvc.controller.Controller;
import ch.swaechter.webcms.core.plugin.Plugin;
import ch.swaechter.webcms.core.plugin.PluginManager;
import ch.swaechter.webcms.core.settings.Settings;
import ch.swaechter.webcms.textplugin.controllers.TextController;

/**
 * This plugin serves as a simple text site plugin that is able to display texts.
 *
 * @author Simon Wächter
 */
public class TextPlugin implements Plugin
{
	/**
	 * Get the system plugin name.
	 */
	@Override
	public String getSystemName()
	{
		return new String("text");
	}

	/**
	 * Get the displayable plugin name.
	 */
	@Override
	public String getDisplayableName()
	{
		return new String("Text");
	}

	/**
	 * Get all initialized controllers.
	 */
	@Override
	public ArrayList<Controller> getControllers(PluginManager pluginmanager, Settings settings)
	{
		return new ArrayList<Controller>(Arrays.asList(new TextController(pluginmanager, settings)));
	}
}
