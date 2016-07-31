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

package ch.swaechter.webcms.adminplugin.controllers;

import ch.swaechter.webcms.adminplugin.models.UserModel;
import ch.swaechter.webcms.core.modules.mvc.controller.Controller;
import ch.swaechter.webcms.core.modules.mvc.view.EmptyView;
import ch.swaechter.webcms.core.modules.mvc.view.ExternalRedirectView;
import ch.swaechter.webcms.core.modules.mvc.view.InternalRedirectView;
import ch.swaechter.webcms.core.modules.mvc.view.ModelView;
import ch.swaechter.webcms.core.modules.mvc.view.View;
import ch.swaechter.webcms.core.plugin.PluginManager;
import ch.swaechter.webcms.core.settings.Settings;

/**
 * This class is responsible for the user actions like the login or logout process.
 *
 * @author Simon Wächter
 */
public class UserController extends Controller
{
	/**
	 * User model for the user interaction.
	 */
	private final UserModel usermodel = new UserModel(getPluginManager(), getSettings());

	/**
	 * Constructor with the plugin manager and the settings.
	 *
	 * @param pluginmanager Plugin manager
	 * @param settings Settings
	 */
	public UserController(PluginManager pluginmanager, Settings settings)
	{
		super(pluginmanager, settings);
	}

	/**
	 * Index action of the user controller.
	 *
	 * @return Normal view
	 */
	public View index()
	{
		ModelView modelview = new ModelView("userindex");
		modelview.addAttribute("modelname", usermodel.getClass().getName());
		return modelview;
	}

	/**
	 * Redirect to an internal site.
	 *
	 * @return Redirect view
	 */
	public View internal()
	{
		return new InternalRedirectView("/user/index");
	}

	/**
	 * Redirect to an external site.
	 *
	 * @return Redirect view
	 */
	public View external()
	{
		return new ExternalRedirectView("http://google.com");
	}

	/**
	 * Redirect to an empty view.
	 *
	 * @return Empty view
	 */
	public View donothing()
	{
		return new EmptyView();
	}
}
