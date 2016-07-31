$(document).ready(function()
{
	setInterval(refreshUser, 5000);
	refreshUser();
	
	$('#form-select-day').submit(function(event)
	{
		event.preventDefault();
		sendForm('select-day');
	});
	
	$('#form-send-request').submit(function(event)
	{
		event.preventDefault();
		sendForm('send-request');
	});
	
	$(document).on('click', '#button-left', function()
	{
		sendRequest('move-camera-left');
	});
	
	$(document).on('click', '#button-up', function()
	{
		sendRequest('move-camera-up');
	});
	
	$(document).on('click', '#button-down', function()
	{
		sendRequest('move-camera-down');
	});
	
	$(document).on('click', '#button-right', function()
	{
		sendRequest('move-camera-right');
	});
	
	function refreshUser()
	{
		getQueue();
		checkQueue();
	}
	
	function getQueue()
	{
		if($('#queue').length)
		{
			$.ajax(
			{
				url: 'requests.php',
				data: 'request=get-queue',
				type: 'post',
				success: function(data)
				{
					$('#content').empty();
					$('#content').prepend(data);
				}
			});
		}
	}
	
	function checkQueue()
	{
		if($('#queue').length)
		{
			$.ajax(
			{
				url: 'requests.php',
				data: 'request=check-queue',
				type: 'post',
				success: function(data)
				{
					var json = $.parseJSON(data);
					if(json.status)
					{
						$.ajax(
						{
							url: 'requests.php',
							data: 'request=enable-camera',
							type: 'post',
							success: function(data)
							{
								$('#content').empty();
								$('#content').prepend(data);
								setTimeout(function()
								{
									$.ajax(
									{
										url: 'requests.php',
										data: 'request=disable-camera',
										type: 'post',
										success: function(data)
										{
											$('#content').empty();
											$('#content').prepend(data);
										}
									});
								}, 30000);
							}
						});
					}
				}
			});
		}
	}
	
	function sendForm(request)
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
	
	function sendRequest(request)
	{
		$.ajax(
		{
			url: 'requests.php',
			data: 'request=' + request,
			type: 'post'
		});
	}
});
