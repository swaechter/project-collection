<?php

require_once('functions.php');

if(!isLoggedIn()) // User is not logged in - but maybe he has some login credentials
{
	if(isUnloggedUser()) // User has credentials - login and reload page
	{
		if(loginUser(getPVar('firstname'), getPVar('lastname'), getPVar('password'))) // Success
		{
			displayPage('content/content-home');
		}
		else
		{
			displayLoginPageWithError(array('errorstatus' => 'Ihre Daten konnten nicht gefunden werden.'));
		}
	}
	else // Show login
	{
		displayLoginPage();
	}
}
else // User is logged in
{
	// Get page value
	$page = getPage();
	
	// Show the content of the specific page
	if(($page == 'home') || (isLoggedIn() && empty($page)))
	{
		displayPage('content/content-home');
	}
	else if($page == 'work-add')
	{
		displayPageWithData('content/content-work-add', array('projects' => getProjects()));
	}
	else if($page == 'work-edit')
	{
		displayPageWithData('content/content-work-edit', array('works' => getWorks()));
	}
	else if($page == 'work-delete')
	{
		displayPageWithData('content/content-work-delete', array('works' => getWorks()));
	}
	else if($page == 'user-create' && isHead())
	{
		displayPage('content/content-user-create');
	}
	else if($page == 'user-edit' && isHead())
	{
		displayPageWithData('content/content-user-edit', array('users' => getUsers()));
	}
	else if($page == 'user-delete' && isHead())
	{
		displayPageWithData('content/content-user-delete', array('users' => getUsers()));
	}
	else if($page == 'customer-create' && isHead())
	{
		displayPage('content/content-customer-create');
	}
	else if($page == 'customer-edit' && isHead())
	{
		displayPageWithData('content/content-customer-edit', array('customers' => getCustomers()));
	}
	else if($page == 'customer-delete' && isHead())
	{
		displayPageWithData('content/content-customer-delete', array('customers' => getCustomers()));
	}
	else if($page == 'project-create' && isHead())
	{
		displayPageWithData('content/content-project-create', array('customers' => getCustomers()));
	}
	else if($page == 'project-edit' && isHead())
	{
		displayPageWithData('content/content-project-edit', array('projects' => getProjects()));
	}
	else if($page == 'project-delete' && isHead())
	{
		displayPageWithData('content/content-project-delete', array('projects' => getProjects()));
	}
	else if($page == 'statistic-work')
	{
		displayPageWithData('content/content-statistic-work', array('months' => getMonthsOfCurrentYear()));
	}
	else if($page == 'statistic-work-user' && isHead())
	{
		displayPageWithData('content/content-statistic-work-user', array('users' => getUsers(), 'months' => getMonthsOfCurrentYear()));
	}
	else if($page == 'statistic-work-customer' && isHead())
	{
		displayPageWithData('content/content-statistic-work-customer', array('customers' => getCustomers()));
	}
	else if($page == 'settings')
	{
		displayPage('content/content-settings');
	}
	else if($page == 'logout')
	{
		logoutUser();
		displayLoginPage();
	}
	else // Or an error, because the page does not exist or the user is not a head
	{
		displayPage('content/content-error');
	}
}

?>
