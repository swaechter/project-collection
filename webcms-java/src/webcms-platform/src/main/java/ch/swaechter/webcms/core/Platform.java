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

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import ch.swaechter.webcms.core.dispatcher.Dispatcher;
import ch.swaechter.webcms.core.plugin.Plugin;
import ch.swaechter.webcms.core.plugin.PluginManager;
import ch.swaechter.webcms.core.settings.Settings;

/**
 * This class represents the WebCMS platform.
 *
 * @author Simon Wächter
 */
public class Platform
{
	/**
	 * Plugin manager that is responsible for the plugins.
	 */
	private final PluginManager pluginmanager;

	/**
	 * Dispatcher that is responsible for all requests and responses.
	 */
	private final Dispatcher dispatcher;

	/**
	 * Constructor with the plugins and the settings.
	 *
	 * @param plugins Plugins
	 * @param settings Settings
	 */
	public Platform(ArrayList<Plugin> plugins, Settings settings)
	{
		pluginmanager = new PluginManager(plugins);
		dispatcher = new Dispatcher(pluginmanager, settings);
	}

	/**
	 * Handle a request and dispatch the correct context and handler.
	 *
	 * @param context Servlet context
	 * @param request HTTP request
	 * @param response HTTP response
	 * @throws IOException Exception in case of an IO problem
	 */
	public void handleRequest(ServletContext context, HttpServletRequest request, HttpServletResponse response) throws IOException
	{
		try
		{
			dispatcher.dispatchContext(dispatcher.getContext(context, request, response));
		}
		catch(Exception exception)
		{
			dispatcher.dispatchFallbackContext(dispatcher.getContext(context, request, response));
		}
	}
}
