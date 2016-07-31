<?php

require_once('libraries/mustache/src/Mustache/Autoloader.php');
require_once('config.php');

// Register the Mustache loader
Mustache_Autoloader::register();

// Session start for cookie usage
session_start();

function displayLoginPage()
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$index = $mustache->loadTemplate('index');
	$content = $mustache->loadTemplate('content/content-login');
	tidyecho($index->render(array('style' => 'styles/style-login.css', 'content' => $content)));
}

// Display the login page with an error message
function displayLoginPageWithError($errorstatus)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$index = $mustache->loadTemplate('index');
	$content = $mustache->loadTemplate('content/content-login');
	tidyecho($index->render(array('style' => 'styles/style-login.css', 'content' => $content, 'errorstatus' => $errorstatus)));
}

// Display the given page with header, content and footer
function displayPage($page)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$index = $mustache->loadTemplate('index');
	$header = $mustache->loadTemplate('modules/header');
	
	// Override if head
	if(isHead())
	{
		$header = $mustache->loadTemplate('modules/header-head');
	}
	
	$content = $mustache->loadTemplate($page);
	$footer = $mustache->loadTemplate('modules/footer');
	tidyecho($index->render(array('style' => 'styles/style.css', 'header' => $header, 'content' => $content, 'footer' => $footer)));
}

// Display the given page with header, content and footer
function displayPageWithData($page, $data)
{
	$premustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$content = $premustache->loadTemplate($page);
	$text = $content->render($data);
	
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$index = $mustache->loadTemplate('index');
	$header = $mustache->loadTemplate('modules/header');
	
	// Override if head
	if(isHead())
	{
		$header = $mustache->loadTemplate('modules/header-head');
	}
	
	$footer = $mustache->loadTemplate('modules/footer');
	tidyecho($index->render(array('style' => 'styles/style.css', 'header' => $header, 'content' => $text, 'footer' => $footer)));
}

// Display a reply page without header, footer etc
function displayReplyPageWithData($page, $data)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$content = $mustache->loadTemplate($page);
	tidyecho($content->render($data));
}

// Display a success box - mostly used in AJAX replies
function displaySuccessBox($message)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$box = $mustache->loadTemplate('replies/status');
	tidyecho($box->render(array('status' => 'alert-success', 'message' => $message)));
}

// Display an error box - mostly used in AJAX replies
function displayErrorBox($message)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$box = $mustache->loadTemplate('replies/status');
	tidyecho($box->render(array('status' => 'alert-danger', 'message' => $message)));
}

// Cleanup and echo the code - if the tidy class was found
function tidyecho($text)
{
	// Does if tidy exist
	if(class_exists('tidy'))
	{
		// Cleanup the code
		$tidy = new tidy();
		$tidy_config = array('indent' => true, 'output-html' => true, 'wrap' => 200);
		$text = $tidy->repairString($text, $tidy_config, 'utf8');
		$text = str_replace('<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01//EN">', '<!DOCTYPE html>', $text); // Tidy cannot handle the HTML5 standard
	}
	echo($text);
}

// Return the current page
function getPage()
{
	return isset($_GET['page']) ? $_GET['page'] : null;
}

// Return the incoming request
function getRequest()
{
	return !empty($_POST['request']) ? $_POST['request'] : null;
}

// Check if the user has the credentials to login
function isUnloggedUser()
{
	return isPVar('firstname') && isPVar('lastname') && isPVar('password') ? true : false;
}

// Check if the user is logged in
function isLoggedIn()
{
	return isset($_SESSION['UserLoginStatus']) ? true : false;
}

// Login a user
function loginUser($firstname, $lastname, $password)
{
	if(isVar($firstname) && isVar($lastname) && isVar($password))
	{
		$mysqli = getConnection();
		if(!$mysqli->connect_errno)
		{
			$firstname = $mysqli->real_escape_string($firstname);
			$lastname = $mysqli->real_escape_string($lastname);
			$password = $mysqli->real_escape_string(hash('sha512', $password));
			$result = $mysqli->query("SELECT * FROM user WHERE firstname='{$firstname}' AND lastname='{$lastname}' AND password='{$password}';");
			if($result->num_rows > 0)
			{
				$row = $result->fetch_assoc();
				$_SESSION['UserID'] = $row['iduser'];
				$_SESSION['UserFirstname'] = $row['firstname'];
				$_SESSION['UserLastname'] = $row['lastname'];
				$_SESSION['UserPosition'] = $row['position'];
				$_SESSION['UserInhousePrice'] = $row['inhouseprice'];
				$_SESSION['UserOuthousePrice'] = $row['outhouseprice'];
				$_SESSION['UserQuota'] = $row['quota'];
				$_SESSION['UserLoginStatus'] = true;
				$result->free();
				$mysqli->close();
				return true;
			}
			else
			{
				$mysqli->close();
			}
		}
	}
	return false;
}

// Logout a user
function logoutUser()
{
	$_SESSION = array();
	session_destroy();
}

// Check if the user is a normal user
function isUser()
{
	return $_SESSION['UserPosition'] == 1 ? true : false;
}

// Check if the user is a head
function isHead()
{
	return $_SESSION['UserPosition'] == 2 ? true : false;
}

// Return a connection
function getConnection()
{
	return new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE);
}

// Add new work
function addWork($idproject, $workdate, $duration, $description)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$iduser = $mysqli->real_escape_string($_SESSION['UserID']);
		$idproject = $mysqli->real_escape_string($idproject);
		$workdate = $mysqli->real_escape_string($workdate);
		$duration = $mysqli->real_escape_string($duration);
		$description = $mysqli->real_escape_string($description);
		$mysqli->query("INSERT INTO work (user_iduser, project_idproject, workdate, duration, description) VALUES({$iduser}, {$idproject}, '{$workdate}', {$duration}, '{$description}');");
		$mysqli->close();
		return true;
	}
	return false;
}

// Edit existing work
function editWork($idwork, $idproject, $workdate, $duration, $description)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$idwork = $mysqli->real_escape_string($idwork);
		$idproject = $mysqli->real_escape_string($idproject);
		$workdate = $mysqli->real_escape_string($workdate);
		$duration = $mysqli->real_escape_string($duration);
		$description = $mysqli->real_escape_string($description);
		$mysqli->query("UPDATE work SET project_idproject={$idproject}, workdate='{$workdate}', duration={$duration}, description='{$description}' WHERE idwork={$idwork};");
		$mysqli->close();
		return true;
	}
	return false;
}

// Delete existing work
function deleteWork($id)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		if($mysqli->query("DELETE FROM work WHERE idwork={$id};"))
		{
			$mysqli->close();
			return true;
		}
		else
		{
			$mysqli->close();
		}
	}
	return false;
}

// Get work
function getWorks()
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$works = array();
		$result = $mysqli->query("SELECT * FROM work LEFT JOIN project ON work.project_idproject=project.idproject");
		while($work = $result->fetch_assoc())
		{
			if((isHead()) || (isUser() && ($work['user_iduser'] == $_SESSION['UserID'])))
			{
				$works[] = $work;
			}
		}
		$result->free();
		$mysqli->close();
		return $works;
	}
	else
	{
		return array();
	}
}

// Get own work
function getWorksForID($iduser)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$works = array();
		$result = $mysqli->query("SELECT * FROM work LEFT JOIN project ON work.project_idproject=project.idproject");
		while($work = $result->fetch_assoc())
		{
			if($work['user_iduser'] == $iduser)
			{
				$works[] = $work;
			}
		}
		$result->free();
		$mysqli->close();
		return $works;
	}
	else
	{
		return array();
	}
}

// Create a new user
function createUser($firstname, $lastname, $password1, $password2, $position, $inhouseprice, $outhouseprice, $quota)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		if($password1 == $password2)
		{
			$firstname = $mysqli->real_escape_string($firstname);
			$lastname = $mysqli->real_escape_string($lastname);
			$password = hash('sha512', $mysqli->real_escape_string($password1));
			$position = $mysqli->real_escape_string($position);
			$inhouseprice = $mysqli->real_escape_string($inhouseprice);
			$outhouseprice = $mysqli->real_escape_string($outhouseprice);
			$quota = $mysqli->real_escape_string($quota);
			$result = $mysqli->query("SELECT * FROM user WHERE firstname='{$firstname}' AND lastname='{$lastname}' AND password='{$password}';");
			if($result->num_rows == 0)
			{
				$mysqli->query("INSERT INTO user (firstname, lastname, password, position, inhouseprice, outhouseprice, quota) VALUES('{$firstname}', '{$lastname}', '{$password}', {$position}, {$inhouseprice}, {$outhouseprice}, {$quota});");
				$mysqli->close();
				return true;
			}
			else
			{
				$result->free();
				$mysqli->close();
			}
		}
	}
	return false;
}

// Edit an existing user
function editUser($iduser, $firstname, $lastname, $position, $inhouseprice, $outhouseprice, $quota)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$firstname = $mysqli->real_escape_string($firstname);
		$lastname = $mysqli->real_escape_string($lastname);
		$position = $mysqli->real_escape_string($position);
		$inhouseprice = $mysqli->real_escape_string($inhouseprice);
		$outhouseprice = $mysqli->real_escape_string($outhouseprice);
		$quota = $mysqli->real_escape_string($quota);
		$mysqli->query("UPDATE user SET firstname='{$firstname}', lastname='{$lastname}', position={$position}, inhouseprice={$inhouseprice}, outhouseprice={$outhouseprice}, quota={$quota} WHERE iduser={$iduser};");
		$mysqli->close();
		return true;
	}
	return false;
}

// Edit an existing user
function editUserPassword($oldpassword, $newpassword)
{
	if($oldpassword == $newpassword)
	{
		$mysqli = getConnection();
		if(!$mysqli->connect_errno)
		{
			$password = hash('sha512', $mysqli->real_escape_string($newpassword));
			$firstname = $_SESSION['UserFirstname'];
			$lastname = $_SESSION['UserLastname'];
			$mysqli->query("UPDATE user SET password='{$password}' WHERE firstname='{$firstname}' AND lastname='{$lastname}';");
			$mysqli->close();
			return true;
		}
	}
	return false;
}

// Delete an existing user
function deleteUser($id)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		if($mysqli->query("DELETE FROM user WHERE iduser={$id};"))
		{
			$mysqli->close();
			return true;
		}
		else
		{
			$mysqli->close();
		}
	}
	return false;
}

// Get all users
function getUsers()
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$users = array();
		$result = $mysqli->query("SELECT * FROM user;");
		while($user = $result->fetch_assoc())
		{
			$users[] = $user;
		}
		$result->free();
		$mysqli->close();
		return $users;
	}
	else
	{
		return array();
	}
}

// Create a new customer
function createCustomer($name, $adress, $townnumber, $town)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$name = $mysqli->real_escape_string($name);
		$adress = $mysqli->real_escape_string($adress);
		$townnumber = $mysqli->real_escape_string($townnumber);
		$town = $mysqli->real_escape_string($town);
		$result = $mysqli->query("SELECT * FROM customer WHERE name='{$name}';");
		if($result->num_rows == 0)
		{
			$mysqli->query("INSERT INTO customer (name, adress, townnumber, town) VALUES('{$name}', '{$adress}', '{$townnumber}', '{$town}');");
			$mysqli->close();
			return true;
		}
		else
		{
			$result->free();
			$mysqli->close();
		}
	}
	return false;
}

// Edit an existing customer
function editCustomer($idcustomer, $name, $adress, $townnumber, $town)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$name = $mysqli->real_escape_string($name);
		$adress = $mysqli->real_escape_string($adress);
		$townnumber = $mysqli->real_escape_string($townnumber);
		$town = $mysqli->real_escape_string($town);
		if($mysqli->query("UPDATE customer SET name='{$name}', adress='{$adress}', townnumber={$townnumber}, town='{$town}' WHERE idcustomer='{$idcustomer}';"))
		{
			$mysqli->close();
			return true;
		}
		else
		{
			$mysqli->close();
		}
	}
	return false;
}

// Delete an existing customer
function deleteCustomer($id)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		if($mysqli->query("DELETE FROM customer WHERE idcustomer={$id};"))
		{
			$mysqli->close();
			return true;
		}
		else
		{
			$mysqli->close();
		}
	}
	return false;
}

// Get all customers
function getCustomers()
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$customers = array();
		$result = $mysqli->query("SELECT * FROM customer;");
		while($customer = $result->fetch_assoc())
		{
			$customers[] = $customer;
		}
		$result->free();
		$mysqli->close();
		return $customers;
	}
	else
	{
		return array();
	}
}

// Create a new project
function createProject($name, $id)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$name = $mysqli->real_escape_string($name);
		$id = $mysqli->real_escape_string($id);
		$result = $mysqli->query("SELECT * FROM project WHERE name='{$name}';");
		if($result->num_rows == 0)
		{
			$mysqli->query("INSERT INTO project (name, customer_idcustomer) VALUES('{$name}', {$id});");
			$mysqli->close();
			return true;
		}
		else
		{
			$result->free();
			$mysqli->close();
		}
	}
	return false;
}

// Edit an existing project
function editProject($idproject, $name, $idcustomer)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$name = $mysqli->real_escape_string($name);
		$mysqli->query("UPDATE project SET name='{$name}', customer_idcustomer={$idcustomer} WHERE idproject={$idproject};");
		$mysqli->close();
		return true;
	}
	return false;
}

// Delete an existing project
function deleteProject($id)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		if($mysqli->query("DELETE FROM project WHERE idproject={$id};"))
		{
			$mysqli->close();
			return true;
		}
		else
		{
			$mysqli->close();
		}
	}
	return false;
}

// Get all projects
function getProjects()
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$projects = array();
		$result = $mysqli->query("SELECT * FROM project;");
		while($project = $result->fetch_assoc())
		{
			$projects[] = $project;
		}
		$result->free();
		$mysqli->close();
		return $projects;
	}
	else
	{
		return array();
	}
}

// Display work of a user for a month
function getWorkForIDForMonth($iduser, $month)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		// Use own user if iduser is null
		if($iduser == null)
		{
			$iduser = $_SESSION['UserID'];
		}
		
		// Select with year, month and a wildcarded day
		$works = array();
		$result = $mysqli->query("SELECT * FROM work LEFT JOIN project ON work.project_idproject=project.idproject WHERE work.workdate LIKE '{$month}-%';");
		while($work = $result->fetch_assoc())
		{
			if($work['user_iduser'] == $iduser)
			{
				$works[] = $work;
			}
		}
		$result->free();
		$mysqli->close();
		
		// Set timezone
		date_default_timezone_set('Europe/Zurich');
		
		// Get days of the month as long month is not the current month . otherwhise take passed days
		$dayspermonth = 0;
		if($month == date('Y-m'))
		{
			$dayspermonth = date('t');
		}
		else
		{
			$params = explode('-', $month);
			$dayspermonth = cal_days_in_month(CAL_GREGORIAN, $params[1], $params[0]);
		}
		
		// Get quota for a day
		$dayquota = $_SESSION['UserQuota'] / 5;
		
		// Worked time of the month
		$hoursworked = 0.0;
		foreach($works as $work)
		{
			$hoursworked = $hoursworked + ($work['duration'] / 60);
		}
		
		// Quota time of the month
		$hoursquota = 0.0;
		$businessday = array('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday'); 
		for($i = 1; $i <= $dayspermonth; $i++)
		{
			$dayname = date('l', strtotime(date('Y') . '-' . date('m') . '-'. $i));
			if(in_array($dayname, $businessday))
			{
				$hoursquota = $hoursquota + $dayquota;
			}
		}
		
		// Difference between worked and quota hours
		$hoursdifference = $hoursworked - $hoursquota;
		
		return array('works' => $works, 'hoursworked' => round($hoursworked, 2), 'hoursquota' => round($hoursquota, 2), 'hoursdifference' => round($hoursdifference, 2));
	}
	return array('work' => array(), 'hoursworked' => 0.0, 'hoursquota' => 0.0, 'hoursdifference' => 0.0);
}

// Get the work for a customer between two dates
function getWorkForCustomerDuringTime($idcustomer, $workdatestart, $workdateend)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		// Select with several left joins
		$works = array();
		$result = $mysqli->query("SELECT * FROM project LEFT JOIN work ON project.idproject=work.project_idproject LEFT JOIN user ON work.user_iduser=work.user_iduser WHERE customer_idcustomer={$idcustomer} AND work.workdate BETWEEN '{$workdatestart}' AND '{$workdateend}' GROUP BY work.idwork;");
		
		$moneyout = 0.0;
		$moneyin = 0.0;
		$moneydifference = 0.0;
		
		while($work = $result->fetch_assoc())
		{
			$works[] = $work;
			$hour = $work['duration'] / 60;
			$in = $work['inhouseprice'] * $hour;
			$out = $work['outhouseprice'] * $hour;
			$difference = $out - $in;
			
			$moneyin = $moneyin + $in;
			$moneyout = $moneyout + $out;
			$moneydifference = $moneydifference + $difference;
			
		}
		$result->free();
		$mysqli->close();
		
		return array('works' => $works, 'moneyout' => round($moneyout, 2), 'moneyin' => round($moneyin, 2), 'moneydifference' => round($moneydifference, 2));
	}
	return array('works' => array(), 'moneyout' => 0.0, 'moneyin' => 0.0, 'moneydifference' => 0.0);
}

// Get the last twelve months
function getMonthsOfCurrentYear()
{
	$months = array();
	date_default_timezone_set('Europe/Zurich');
	for($i = 1; $i <= 12; $i++)
	{
		$months[] = array('month' => date('Y-' . $i));
	}
	return $months;
}

// Check if the current string does exist and is not empty
function isVar($var)
{
	return !empty($var) && strlen(trim($var)) > 0 ? true : false;
}

// Same version as isVar but for post variables
function isPVar($var)
{
	return isset($_POST[$var]) && strlen(trim($_POST[$var])) > 0 ? true : false;
}

// Return an existing post variable
function getPVar($name)
{
	return $_POST[$name];
}

?>
