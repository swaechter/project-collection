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

package ch.swaechter.webcms.core.modules.resource;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import ch.swaechter.webcms.core.Globals;
import ch.swaechter.webcms.core.dispatcher.Context;
import ch.swaechter.webcms.core.dispatcher.Handler;
import ch.swaechter.webcms.core.plugin.Plugin;
import ch.swaechter.webcms.core.plugin.PluginManager;
import ch.swaechter.webcms.core.settings.Settings;
import ch.swaechter.webcms.core.utils.StringUtil;

/**
 * This class represents the resource handler that handles system resources.
 *
 * @author Simon Wächter
 */
public class ResourceHandler implements Handler
{
	private final PluginManager pluginmanager;

	private final Settings settings;

	public ResourceHandler(PluginManager pluginmanager, Settings settings)
	{
		this.pluginmanager = pluginmanager;
		this.settings = settings;
	}

	@Override
	public boolean isContextSupported(Context context)
	{
		String uripath = context.getRequest().getRequestURI().substring(context.getRequest().getContextPath().length());
		if(uripath.startsWith(Globals.DIRECTORY_SEPARATOR + settings.getResourcePrefix()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	@Override
	public void dispatchContext(Context context) throws Exception
	{
		String uripath = context.getRequest().getRequestURI().substring(context.getRequest().getContextPath().length());
		String filepath = StringUtil.trimFirstCharacters(uripath, Globals.DIRECTORY_SEPARATOR + settings.getResourcePrefix());
		if(filepath.length() > 0 && !filepath.equals(Globals.DIRECTORY_SEPARATOR))
		{
			InputStream servletinputstream = context.getContext().getResourceAsStream(Globals.WEBAPP_WEBINF_DIRECTORY + filepath);
			if(servletinputstream != null)
			{
				copyStream(servletinputstream, context.getResponse().getOutputStream());
			}
			else
			{
				for(Plugin plugin : pluginmanager.getPlugins())
				{
					InputStream plugininputstream = plugin.getClass().getResourceAsStream(filepath);
					if(plugininputstream != null)
					{
						copyStream(plugininputstream, context.getResponse().getOutputStream());
					}
				}
			}
		}
	}

	/**
	 * Copy the input stream to the output stream.
	 *
	 * @param inputstream Input stream
	 * @param outputstream Output stream
	 * @throws IOException An exception in case of an IO problem
	 */
	private void copyStream(InputStream inputstream, OutputStream outputstream) throws IOException
	{
		int counter = 0;
		byte buffer[] = new byte[8192];
		while((counter = inputstream.read(buffer, 0, buffer.length)) > 0)
		{
			outputstream.write(buffer, 0, counter);
			outputstream.flush();
		}
		outputstream.close();
		inputstream.close();
	}
}
