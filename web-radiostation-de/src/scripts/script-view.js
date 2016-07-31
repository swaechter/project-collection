// Load existing tracks on page load
$(document).ready(function()
{
	reloadTracks();
	setInterval("reloadTracks()", 2000);
});

// Load existing tracks and filter them
$(document).ready(function()
{
	$('#playdate').keyup(function(event)
	{
		$.ajax(
		{
			url: 'requests.php',
			type: 'post',
			dataType: 'json',
			data: {'request' : 'search', 'playdate' : $('#playdate').val()},
			success: function(data)
			{
				$('#tracks').empty();
				if(data.error)
				{
					$('#tracks').append(data.error);
				}
				else if (data.success)
				{
					$('#tracks').append(data.success);
				}
				else
				{
					$.each(data, function(i, item)
					{
						$('#tracks').append('<p>[' + item.playdate + ']  ' + item.title + ' (Album ' + item.album + ') von ' + item.interpret + ', ' + item.year + '</p>');
					});
				}
			}
		});
	});
});

// Reload tracks
function reloadTracks()
{
	if($("#playdate").val().length == 0)
	{
		$.ajax(
		{
			url: 'requests.php',
			type: 'post',
			dataType: 'json',
			data: {'request' : 'view'}, 
			success: function(data)
			{
				$('#tracks').empty();
				if(data.error)
				{
					$('#tracks').append(data.error);
				}
				else if (data.success)
				{
					$('#tracks').append(data.success);
				}
				else
				{
					$.each(data, function(i, item)
					{
						$('#tracks').append('<p>[' + item.playdate + ']  ' + item.title + ' (Album ' + item.album + ') von ' + item.interpret + ', ' + item.year + '</p>');
					});
				}
			}
		});
	}
}
