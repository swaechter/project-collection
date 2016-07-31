<?php

require('libraries/mustache/src/Mustache/Autoloader.php');
require('config.php');

// Register the Mustache loader
Mustache_Autoloader::register();

// Session start for cookie usage
session_start();

// Display a page with a specific template and data
function displayPage($template, $data)
{
	$premustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$content = $premustache->loadTemplate($template);
	$text = $content->render($data);
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$index = $mustache->loadTemplate('index');
	echo $index->render(array('content' => $text));
}

// Display a reply page with content
function displayReplyPage($reply, $data)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$content = $mustache->loadTemplate($reply);
	echo $content->render($data);
}

// Display a success box - mostly used in AJAX replies
function displaySuccessBox($message)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$box = $mustache->loadTemplate('replies/status');
	echo $box->render(array('status' => 'alert-success', 'message' => $message));
}

// Display an error box - mostly used in AJAX replies
function displayErrorBox($message)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$box = $mustache->loadTemplate('replies/status');
	echo $box->render(array('status' => 'alert-danger', 'message' => $message));
}

// Echo a variable
function displayArray($array)
{
	echo json_encode($array);
}

// Make the whole panorama picture
function capturePanoramaImage()
{
	sendCommand(MOVE_HOME);
	sendCommand(MOVE_LEFT);
	sendCommand(MOVE_LEFT);
	sendCommand(MOVE_LEFT);
	sendCommand(MOVE_LEFT);
	sendCommand(MOVE_LEFT);
	sendCommand(MOVE_LEFT);
	wait();
	wait();
	
	makeImage(0);
	
	sendCommand(MOVE_RIGHT);
	sendCommand(MOVE_RIGHT);
	sendCommand(MOVE_RIGHT);
	wait();
	
	makeImage(1);
	
	sendCommand(MOVE_RIGHT);
	sendCommand(MOVE_RIGHT);
	sendCommand(MOVE_RIGHT);
	wait();
	
	makeImage(2);
	
	sendCommand(MOVE_RIGHT);
	sendCommand(MOVE_RIGHT);
	sendCommand(MOVE_RIGHT);
	wait();
	
	makeImage(3);
	
	sendCommand(MOVE_RIGHT);
	sendCommand(MOVE_RIGHT);
	sendCommand(MOVE_RIGHT);
	wait();
	
	makeImage(4);
	
	appendImages();
	
	sendCommand(MOVE_HOME);
}

// Send a command via cURL to the remote camera
function sendCommand($command)
{
	$curl = curl_init();
	curl_setopt($curl, CURLOPT_URL, $command);
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
	$content = curl_exec($curl);
	curl_close($curl);
	return $content;
}

// Make an image
function makeImage($counter)
{
	$image = IMAGE_NAME_INPUT . $counter . IMAGE_TYPE;
	$content = sendCommand(GET_IMAGE);
	file_put_contents($image, $content);
}

// Append all images to one panorama image
function appendImages()
{
	$input = array();
	for($i = 0; $i < IMAGE_COUNT; $i++)
	{
		$input[] = imagecreatefromjpeg(IMAGE_NAME_INPUT . $i . IMAGE_TYPE);
	}
	
	$output = imagecreatetruecolor(IMAGE_COUNT * IMAGE_X - IMAGE_COUNT * IMAGE_BORDER, IMAGE_Y);
	
	for($i = 0; $i < IMAGE_COUNT; $i++)
	{
		$x = IMAGE_X * $i - IMAGE_BORDER * $i;
		imagecopy($output, $input[$i], $x, 0, 0, 0, IMAGE_X, IMAGE_Y);
		imagedestroy($input[$i]);
	}
	
	imagejpeg($output, IMAGE_NAME_OUTPUT . 'current' . IMAGE_TYPE);
	if(date('i') == 0)
	{
		imagejpeg($output, IMAGE_NAME_OUTPUT . date('Y_m_d_h') . IMAGE_TYPE);
	}
	
	imagedestroy($output);
}

// Wait for 2 seconds, so the camera doesn't create an image during the movement
function wait()
{
	sleep(2);
}

// Get the last 15 days
function getDates()
{
	$dates = array();
	for($day = 0; $day < 15; $day++)
	{
		$iterationday = strtotime('-' . $day . 'day');
		$dates[] = array('value' => date('Y-m-d', $iterationday));
	}
	return $dates;
}

// Get the existing images for a hour from a date
function getHours($date)
{
	$hours = array();
	$filedate = str_replace('-', '_', $date);
	for($i = 0; $i < 24; $i++)
	{
		if(file_exists(IMAGE_NAME_OUTPUT . $filedate . '_' . $i . IMAGE_TYPE))
		{
			$hours[] = array('value' => $i, 'readablevalue' => $i . ':00', 'date' => $filedate);
		}
	}
	return $hours;
}

// Add an item to the queue
function addUserToQueue($username)
{
	// Insert username
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$username = $mysqli->real_escape_string($username);
		$datetime = date('Y-m-d H:i:s');
		if($mysqli->query("INSERT INTO queue (username, datetime, pingdatetime) VALUES ('{$username}', '{$datetime}', '{$datetime}');"))
		{
			$_SESSION['username'] = $username;
			$_SESSION['started'] = false;
			$mysqli->close();
			return true;
		}
	}
	return false;
}

// Remove an item from the queue
function removeUserFromQueue()
{
	// Save username
	$username = $_SESSION['username'];
	
	// Unset username and status
	$_SESSION['username'] = null;
	$_SESSION['started'] = false;
	
	// Delete username
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$mysqli->query("DELETE FROM queue WHERE username='{$username}';");
		$mysqli->close();
	}
	return false;
}

// Clean the queue - remove expired sessions
function updateQueue()
{
	$nowtimestamp = time();
	$pingdatetime = date('Y-m-d H:i:s');
	$username = $_SESSION['username'];
	
	foreach(getQueueItems() as $item)
	{
		$pingtimestamp = strtotime($item['pingdatetime']);
		
		if($item['username'] == $username)
		{
			$mysqli = getConnection();
			if(!$mysqli->connect_errno)
			{
				$mysqli->query("UPDATE queue SET pingdatetime='{$pingdatetime}' WHERE username='{$username}';");
				$mysqli->close();
			}
		}
		
		if(($nowtimestamp - $pingtimestamp) > 40)
		{
			$itemusername = $item['username'];
			$mysqli = getConnection();
			if(!$mysqli->connect_errno)
			{
				$mysqli->query("DELETE FROM queue WHERE username='{$itemusername}';");
				$mysqli->close();
			}
		}
	}
}

// Get the first queue user and the own username, so the client can make a comparison
function getQueueUserCheck()
{
	$data = array();
	$items = getQueueItems();
	
	if(isset($items[0]))
	{
		if($items[0]['username'] == $_SESSION['username'])
		{
			if($_SESSION['started'] == false)
			{
				$_SESSION['started'] = true;
				$data['status'] = true;
			}
		}
	}
	
	return $data;
}

// Get all items from the queue
function getQueueItems()
{
	$items = array();
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$result = $mysqli->query("SELECT * FROM queue ORDER BY datetime ASC;");
		while($item = $result->fetch_assoc())
		{
			$items[] = $item;
		}
		$result->free();
		$mysqli->close();
	}
	return $items;
}

// Return a connection
function getConnection()
{
	return new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE);
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

// Check if POST variable does exist
function isPVar($var)
{
	return isset($_POST[$var]) && strlen(trim($_POST[$var])) > 0 ? true : false;
}

// Return an existing POST variable
function getPVar($name)
{
	return $_POST[$name];
}

?>
