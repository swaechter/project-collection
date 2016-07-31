$(document).ready(function()
{	
	$('#form-work-add').submit(function(event)
	{
		event.preventDefault();
		sendRequest('work-add');
	});
	
	$('#form-work-edit').submit(function(event)
	{
		event.preventDefault();
		sendRequest('work-edit');
	});
	
	$(document).on('submit', '#form-work-edit-panel', function(event)
	{
		event.preventDefault();
		sendRequest('work-edit-panel');
	});
	
	$('#form-work-delete').submit(function(event)
	{
		event.preventDefault();
		sendRequest('work-delete');
	});
	
	$('#form-user-create').submit(function(event)
	{
		event.preventDefault();
		sendRequest('user-create');
	});
	
	$('#form-user-edit').submit(function(event)
	{
		event.preventDefault();
		sendRequest('user-edit');
	});
	
	$(document).on('submit', '#form-user-edit-panel', function(event)
	{
		event.preventDefault();
		sendRequest('user-edit-panel');
	});
	
	$('#form-user-delete').submit(function(event)
	{
		event.preventDefault();
		sendRequest('user-delete');
	});
	
	$('#form-customer-create').submit(function(event)
	{
		event.preventDefault();
		sendRequest('customer-create');
	});
	
	$('#form-customer-edit').submit(function(event)
	{
		event.preventDefault();
		sendRequest('customer-edit');
	});
	
	$(document).on('submit', '#form-customer-edit-panel', function(event)
	{
		event.preventDefault();
		sendRequest('customer-edit-panel');
	});
	
	$('#form-customer-delete').submit(function(event)
	{
		event.preventDefault();
		sendRequest('customer-delete');
	});
	
	$('#form-project-create').submit(function(event)
	{
		event.preventDefault();
		sendRequest('project-create');
	});
	
	$('#form-project-edit').submit(function(event)
	{
		event.preventDefault();
		sendRequest('project-edit');
	});
	
	$(document).on('submit', '#form-project-edit-panel', function(event)
	{
		event.preventDefault();
		sendRequest('project-edit-panel');
	});
	
	$('#form-project-delete').submit(function(event)
	{
		event.preventDefault();
		sendRequest('project-delete');
	});
	
	$('#form-statistic-work').submit(function(event)
	{
		event.preventDefault();
		sendRequest('statistic-work');
	});
	
	$('#form-statistic-work-user').submit(function(event)
	{
		event.preventDefault();
		sendRequest('statistic-work-user');
	});
	
	$('#form-statistic-work-customer').submit(function(event)
	{
		event.preventDefault();
		sendRequest('statistic-work-customer');
	});
	
	$('#form-settings').submit(function(event)
	{
		event.preventDefault();
		sendRequest('settings');
	});
	
	function sendRequest(request)
	{
		var requeststring = '&request=' + request;
		$.ajax(
		{
			url: 'requests.php',
			data: $('#form-' + request).serialize() + requeststring,
			type: 'post',
			success: function(data)
			{
				$('#content').empty();
				$('#content').prepend(data);
			}
		});
	}
});
