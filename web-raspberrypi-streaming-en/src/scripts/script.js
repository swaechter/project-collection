$(document).ready(function()
{
	$('#form-local-camera-state').submit(function(event)
	{
		event.preventDefault();
		sendRequest('local-camera-state');
	});
	
	$('#form-local-camera-stream').submit(function(event)
	{
		event.preventDefault();
		sendRequest('local-camera-stream');
	});
	
	$('#form-local-camera-video').submit(function(event)
	{
		event.preventDefault();
		sendRequest('local-camera-video');
	});
	
	$('#form-remote-cameras-add').submit(function(event)
	{
		event.preventDefault();
		sendRequest('remote-cameras-add');
	});
	
	$('#form-remote-cameras-remove').submit(function(event)
	{
		event.preventDefault();
		sendRequest('remote-cameras-remove');
	});
	
	$('#form-remote-cameras-stream').submit(function(event)
	{
		event.preventDefault();
		sendRequest('remote-cameras-stream');
	});
	
	function sendRequest(request)
	{
		$.ajax(
		{
			url: 'requests.php',
			data: $('#form-' + request).serialize() + '&request=' + request,
			type: 'post',
			success: function(data)
			{
				$('#content').empty();
				$('#content').prepend(data);
			}
		});
	}
});
