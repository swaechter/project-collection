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

package ch.swaechter.webcms.core.modules.mvc;

import java.lang.reflect.Method;

import ch.swaechter.webcms.core.Globals;
import ch.swaechter.webcms.core.dispatcher.Context;
import ch.swaechter.webcms.core.dispatcher.Handler;
import ch.swaechter.webcms.core.modules.mvc.controller.Controller;
import ch.swaechter.webcms.core.modules.mvc.view.View;
import ch.swaechter.webcms.core.plugin.Plugin;
import ch.swaechter.webcms.core.plugin.PluginManager;
import ch.swaechter.webcms.core.settings.Settings;
import ch.swaechter.webcms.core.utils.StringUtil;

/**
 * This class represents a handler that handles all MVC component.
 *
 * @author Simon Wächter
 */
public class MvcHandler implements Handler
{
	/**
	 * Plugin manager who is responsible for all plugins.
	 */
	private final PluginManager pluginmanager;

	/**
	 * Settings of the system.
	 */
	private final Settings settings;

	/**
	 * Constructor with the plugin manager and the settings.
	 *
	 * @param pluginmanager Plugin manager
	 * @param settings Settings
	 */
	public MvcHandler(PluginManager pluginmanager, Settings settings)
	{
		this.pluginmanager = pluginmanager;
		this.settings = settings;
	}

	@Override
	public boolean isContextSupported(Context context)
	{
		return true;
	}

	@Override
	public void dispatchContext(Context context) throws Exception
	{
		{
			String path =  StringUtil.trimFirstCharacters(context.getPath(), Globals.DIRECTORY_SEPARATOR);
			String[] parameters = path.split(Globals.DIRECTORY_SEPARATOR);
			String controllerstring = (parameters.length > 0) ? parameters[0] : new String();
			String actionstring = (parameters.length > 1) ? parameters[1] : new String();
			String controllername = controllerstring + Globals.CONTROLLER_CLASS_SUFFIX;
			for(Plugin plugin : pluginmanager.getPlugins())
			{
				for(Controller controller : plugin.getControllers(pluginmanager, settings))
				{
					if(controller.getClass().getSimpleName().equalsIgnoreCase(controllername))
					{
						try
						{
							Method method = controller.getClass().getDeclaredMethod(actionstring);
							View view = (View) method.invoke(controller);
							view.processContext(plugin, context);
							return;
						}
						catch(Exception exception)
						{
							if(!context.getPath().equals(settings.getDefaultRoute()))
							{
								dispatchContext(new Context(settings.getDefaultRoute(), context.getContext(), context.getRequest(), context.getResponse()));
							}
							else
							{
								throw new Exception();
							}
						}
					}
				}
			}
			dispatchContext(new Context(settings.getDefaultRoute(), context.getContext(), context.getRequest(), context.getResponse()));
		}
	}
}
