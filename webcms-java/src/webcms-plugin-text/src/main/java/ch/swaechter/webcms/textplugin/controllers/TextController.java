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

package ch.swaechter.webcms.textplugin.controllers;

import ch.swaechter.webcms.core.modules.mvc.controller.Controller;
import ch.swaechter.webcms.core.modules.mvc.view.ModelView;
import ch.swaechter.webcms.core.modules.mvc.view.View;
import ch.swaechter.webcms.core.plugin.PluginManager;
import ch.swaechter.webcms.core.settings.Settings;
import ch.swaechter.webcms.textplugin.models.TextModel;

/**
 * This class is responsible for the text management.
 *
 * @author Simon Wächter
 */
public class TextController extends Controller
{
	/**
	 * Text model for the text interaction.
	 */
	private final TextModel textmodel = new TextModel(getPluginManager(), getSettings());

	/**
	 * Constructor with the plugin manager and the settings.
	 *
	 * @param pluginmanager Plugin manager
	 * @param settings Settings
	 */
	public TextController(PluginManager pluginmanager, Settings settings)
	{
		super(pluginmanager, settings);
	}

	/**
	 * Index action of the text controller.
	 *
	 * @return Normal view
	 */
	public View index()
	{
		ModelView modelview = new ModelView("textindex");
		modelview.addAttribute("modelname", textmodel.getClass().getName());
		return modelview;
	}
}
