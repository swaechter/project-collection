package ch.swaechter.webcms.core.dispatcher;

public interface Handler
{
	public boolean isContextSupported(Context context);

	public void dispatchContext(Context context) throws Exception;
}
