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

package ch.swaechter.webcms.core.modules.mvc.view;

import ch.swaechter.webcms.core.dispatcher.Context;
import ch.swaechter.webcms.core.plugin.Plugin;

/**
 * This class is a placeholder view used for action that don't return data or redirect to another
 * site.
 *
 * @author Simon Wächter
 */
public class EmptyView implements View
{
	/**
	 * Process nothing because the current view is a placeholder view.
	 */
	@Override
	public void processContext(Plugin plugin, Context context) throws Exception
	{
		// Do nothing
	}
}
