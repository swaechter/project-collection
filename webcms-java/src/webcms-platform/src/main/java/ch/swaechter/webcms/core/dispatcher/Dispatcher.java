package ch.swaechter.webcms.core.dispatcher;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import ch.swaechter.webcms.core.modules.mvc.MvcHandler;
import ch.swaechter.webcms.core.modules.resource.ResourceHandler;
import ch.swaechter.webcms.core.plugin.PluginManager;
import ch.swaechter.webcms.core.settings.Settings;

public class Dispatcher
{
	private ArrayList<Handler> handlers = new ArrayList<>();

	public Dispatcher(PluginManager pluginmanager, Settings settings)
	{
		handlers.add(new ResourceHandler(pluginmanager, settings));
		handlers.add(new MvcHandler(pluginmanager, settings));
	}
	
	public Context getContext(ServletContext context, HttpServletRequest request, HttpServletResponse response)
	{
		String path = request.getRequestURI().substring(request.getContextPath().length());
		return new Context(path, context, request, response);
	}

	public void dispatchContext(Context context) throws Exception
	{
		for(Handler handler : handlers)
		{
			if(handler.isContextSupported(context))
			{
				handler.dispatchContext(context);
				break;
			}
		}
	}

	public void dispatchFallbackContext(Context context) throws IOException
	{
		PrintWriter writer = context.getResponse().getWriter();
		writer.println("An internal error occured!");
		writer.close();
	}
}
