<?php

define('MYSQL_HOST', '127.0.0.1');
define('MYSQL_USER', 'root');
define('MYSQL_PASSWORD', '123456aA');
define('MYSQL_DATABASE', 'tracks');

require_once('libraries/getID3/getid3/getid3.php');
require_once('libraries/mustache/src/Mustache/Autoloader.php');

Mustache_Autoloader::register();

function jsonecho($status, $text)
{
	$array = array($status => $text);
	echo json_encode($array);
}

function displayViewPage()
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	
	$index = $mustache->loadTemplate('index');
	
	$content= $mustache->loadTemplate('content-view');
	
	echo($index->render(array('script' => 'scripts/script-view.js', 'content' => $content)));
}

function displayAddPage($status)
{
	$mustache = new Mustache_Engine(array('loader' => new Mustache_Loader_FilesystemLoader('templates')));
	
	$index = $mustache->loadTemplate('index');
	
	$content= $mustache->loadTemplate('content-add');
	
	$text = $content->render(array('status' => $status));
	
	echo($index->render(array('script' => 'scripts/script-add.js', 'content' => $text)));
}

function getConnection()
{
	return new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DATABASE);
}

function getRequest()
{
	return !empty($_POST['request']) ? $_POST['request'] : null;
}

function getFile()
{
	return !empty($_GET['file']) ? $_GET['file'] : null;
}

function getPlayDate()
{
	return !empty($_POST['playdate']) ? $_POST['playdate'] : null;
}

function getDateTime()
{
	date_default_timezone_set('Europe/Zurich');
	return date('Y-m-d H:i:s');
}

function addTrack($filename)
{
	$filename = '../' . $filename;
	$information = getID3Information($filename);
	if($information)
	{
		$mysqli = getConnection();
		if(!mysqli_connect_errno())
		{
			$title = $information['title'];
			$interpret = $information['interpret'];
			$album = $information['album'];
			$year = $information['year'];
			$datetime = getDateTime();
			$mysqli->query("INSERT INTO tracks (title, interpret, album, year, playdate) VALUES('{$title}', '{$interpret}', '{$album}', {$year}, '{$datetime}');");
			if($result = $mysqli->query("SELECT title, interpret, album, year, playdate FROM tracks;"))
			{
				$result->free();
				$mysqli->close();
				return true;
			}
		}
	}
	return false;
}

function getTracks()
{
	$mysqli = getConnection();
	if(!mysqli_connect_errno())
	{
		if($result = $mysqli->query("SELECT title, interpret, album, year, playdate FROM tracks;"))
		{
			$rows = array();
			while($row = $result->fetch_assoc())
			{
				$rows[] = $row;
			}
			$rows = array_reverse($rows, false);
			$result->free();
			$mysqli->close();
			return $rows;
		}
	}
	return null;
}

function getID3Information($filename)
{
	if(file_exists($filename))
	{
		$information = array();
		$id3information = getID3Object($filename);
		$information['title'] = $id3information['tags']['id3v1']['title'][0];
		$information['interpret'] = $id3information['tags']['id3v1']['artist'][0];
		$information['album'] = $id3information['tags']['id3v1']['album'][0];
		$information['year'] = $id3information['tags']['id3v1']['year'][0];
		return $information;
	}
	return null;
}

function getID3Object($filename)
{
	$id3 = new getID3();
	$information = $id3->analyze($filename);
	getid3_lib::CopyTagsToComments($information);
	return $information;
}

?>
