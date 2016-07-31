<?php

require_once('functions.php');

$page = getPage(); // Get the page value and check if it is a valid one

if($page == 'home' || empty($page))
{
	displayPage('content/content-home', array());
}
else if($page == 'local-camera')
{
	displayPage('content/content-local-camera', array('modes' => getCameraModes(), 'videos' => getAllVideos()));
}
else if($page == 'remote-cameras')
{
	displayPage('content/content-remote-cameras', array('cameras' => getRemoteCameras()));
}
else // Or an error, because the page does not exist
{
	displayPage('content/content-error', array());
}

?>
