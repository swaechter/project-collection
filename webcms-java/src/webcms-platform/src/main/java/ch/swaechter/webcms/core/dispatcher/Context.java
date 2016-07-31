package ch.swaechter.webcms.core.dispatcher;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Context
{
	private final String path;

	private final ServletContext context;

	private final HttpServletRequest request;

	private final HttpServletResponse response;

	public Context(String path, ServletContext context, HttpServletRequest request, HttpServletResponse response)
	{
		this.path = path;
		this.context = context;
		this.request = request;
		this.response = response;
	}

	public String getPath()
	{
		return path;
	}

	public ServletContext getContext()
	{
		return context;
	}

	public HttpServletRequest getRequest()
	{
		return request;
	}

	public HttpServletResponse getResponse()
	{
		return response;
	}
}
