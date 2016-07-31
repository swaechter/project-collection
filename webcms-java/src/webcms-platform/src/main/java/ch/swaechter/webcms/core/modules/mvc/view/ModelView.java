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

import java.util.HashMap;
import java.util.Map;

import ch.swaechter.webcms.core.Globals;
import ch.swaechter.webcms.core.dispatcher.Context;
import ch.swaechter.webcms.core.plugin.Plugin;
import freemarker.cache.ClassTemplateLoader;
import freemarker.cache.MultiTemplateLoader;
import freemarker.cache.TemplateLoader;
import freemarker.cache.WebappTemplateLoader;
import freemarker.template.Configuration;
import freemarker.template.Template;
import freemarker.template.TemplateDirectiveModel;
import kr.pe.kwonnam.freemarker.inheritance.BlockDirective;
import kr.pe.kwonnam.freemarker.inheritance.ExtendsDirective;
import kr.pe.kwonnam.freemarker.inheritance.PutDirective;

/**
 * This class represents a simple model view that loads and processes a template file with the given
 * attributes.
 *
 * @author Simon Wächter
 */
public class ModelView implements View
{
	/**
	 * File path to the model file.
	 */
	private final String filepath;

	/**
	 * Attributes that are passed to the model file.
	 */
	private HashMap<String, Object> attributes;

	/**
	 * Constructor with the file path of the model file.
	 *
	 * @param filepath File path of the model file
	 */
	public ModelView(String filepath)
	{
		this.filepath = filepath;
		this.attributes = new HashMap<>();
	}

	/**
	 * Add an object to the attribute list.
	 *
	 * @param key Location to insert the object
	 * @param value Object for the location
	 */
	public void addAttribute(String key, Object value)
	{
		attributes.put(key, value);
	}

	/**
	 * Get an object from the given location.
	 *
	 * @param key Location of the object
	 * @return Object of the location
	 */
	public Object getAttribute(String key)
	{
		return attributes.get(key);
	}

	/**
	 * Get all attributes.
	 *
	 * @return All attributes as hash map
	 */
	public HashMap<String, Object> getAllAttributes()
	{
		return attributes;
	}

	/**
	 * Process the view based on the model and write to the response stream.
	 */
	@Override
	public void processContext(Plugin plugin, Context context) throws Exception
	{
		// Collect the layout commands
		Map<String, TemplateDirectiveModel> layout = new HashMap<String, TemplateDirectiveModel>();
		layout.put("extends",  new ExtendsDirective());
		layout.put("put", new PutDirective());
		layout.put("block", new BlockDirective());

		// Create the configuration and add the layout commands
		Configuration configuration = new Configuration(Configuration.getVersion());
		configuration.setSharedVariable("layout", layout);

		// Load the base template
		WebappTemplateLoader baseloader = new WebappTemplateLoader(context.getContext(), Globals.DIRECTORY_SEPARATOR + Globals.WEBAPP_WEBINF_DIRECTORY);

		// Load the content template
		ClassTemplateLoader contentloader = new ClassTemplateLoader(plugin.getClass(), Globals.DIRECTORY_SEPARATOR);

		// Merge the loaders
		TemplateLoader loaders[] = new TemplateLoader[] { baseloader, contentloader };
		MultiTemplateLoader multiloader = new MultiTemplateLoader(loaders);

		// Set the loader
		configuration.setTemplateLoader(multiloader);

		// Get the template and parse it
		configuration.getTemplate(Globals.WEBAPP_FALLBACK_VIEW_FILE);
		Template template = configuration.getTemplate(filepath + Globals.WEBAPP_VIEW_EXTENSION);
		template.process(attributes, context.getResponse().getWriter());
	}
}
