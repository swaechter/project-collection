<?php

require_once('libraries/mustache/src/Mustache/Autoloader.php');
require_once('config.php');

// Register the Mustache loader
Mustache_Autoloader::register();

// Display the given page with content, header and footer
function displayPage($page, $data)
{
	$premustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	$content = $premustache->loadTemplate($page);
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

// Set own camera mode
function setCameraMode($id)
{
	switch($id)
	{
		case 1:
		{
			stopEverything();
			return true;
		}
		case 2:
		{
			stopEverything();
			startOwnCamera();
			return true;
		}
		case 3:
		{
			stopEverything();
			startOwnMonitoring();
			return true;
		}
		default:
		{
			return false;
		}
	}
}

// Get the current camera modes. The active mode has an additional flag called 'selected'
function getCameraModes()
{
	$modes = array();
	$modes[] = array('value' => 1, 'name' => 'Off');
	$modes[] = array('value' => 2, 'name' => 'Streaming');
	$modes[] = array('value' => 3, 'name' => 'Monitoring');
	
	exec("pgrep vlc", $output, $return);
	if($return == 0)
	{
		$modes[1]["selected"] = "selected";
	}
	
	exec("pgrep motion", $output, $return);
	if($return == 0)
	{
		$modes[2]["selected"] = "selected";
	}
	
	return $modes;
}

// Start own camera
function startOwnCamera()
{
	shell_exec("sudo raspivid -o - -t 9999999 -h 480 -w 720 |cvlc -vvv stream:///dev/stdin --sout '#standard{access=http,mux=ts,dst=:" . CAMERA_PORT . "}' :demux=h264 > /dev/null &");
}

// Start own monitoring
function startOwnMonitoring()
{
	shell_exec("sudo ./executables/motion -n -c data/motion-mmalcam.conf > /dev/null &");
}

// Stop stream or monitoring
function stopEverything()
{
	shell_exec("sudo kill $(ps aux | grep 'vlc' | awk '{print $2}')");
	shell_exec("sudo kill $(ps aux | grep 'motion' | awk '{print $2}')");
}

// Stream a camera
function streamCamera($ip)
{
	displayReplyPage('replies/reply-stream', array('ip' => $ip));
}

// Stream a video
function streamVideo($video)
{
	$ip = "data/videos/" . $video;
	displayReplyPage('replies/reply-video', array('ip' => $ip));
}

// Add a remote camera
function addRemoteCamera($ipwithport)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$ipwithport = $mysqli->real_escape_string($ipwithport);
		$mysqli->query("INSERT INTO video (ip) VALUES('{$ipwithport}');");
		$mysqli->close();
	}
}

// Remove a remote camera
function removeRemoteCamera($ipwithport)
{
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		if($mysqli->query("DELETE FROM video WHERE ip='{$ipwithport}';"))
		{
			$mysqli->close();
		}
	}
	return false;
}

// Get all saved remote cameras
function getRemoteCameras()
{
	$videos = array();
	$mysqli = getConnection();
	if(!$mysqli->connect_errno)
	{
		$result = $mysqli->query("SELECT * FROM video;");
		while($video = $result->fetch_assoc())
		{
			$videos[] = $video;
		}
		$result->free();
		$mysqli->close();
	}
	return $videos;
}

// Get the IP of the Raspberry Pi system
function getCameraIpWithPort()
{
	$command = "/sbin/ifconfig eth0 | grep 'inet addr:' | cut -d: -f2 | awk '{ print $1}'";
	return exec($command) . ":" . CAMERA_PORT;
}

// Get all videos in an array
function getAllVideos()
{
	$videos = array();
	if($handle = opendir('data/videos/'))
	{
		while(false !== ($entry = readdir($handle)))
		{
			if($entry != "." && $entry != ".." && strpos($entry, '.avi') !== false)
			{
				$date = $entry;
				$date = substr($date, 3);
				$date = substr($date, 0, -4);
				$year = substr($date, 0, 4);
				$month = substr($date, 4, 2);
				$day = substr($date, 6, 2);
				$hour = substr($date, 8, 2);
				$minute = substr($date, 10, 2);
				$second = substr($date, 12, 2);
				
				$video = array();
				$video['file'] = $entry;
				$video['date'] = $day . "." . $month . "." . $year . " - " . $hour . ":" . $minute . ":" . $second;
				$videos[] = $video;
			}
		}
		closedir($handle);
	}
	return $videos;
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
