<?php

require('functions.php');

$page = getPage();

if($page == 'gallery')
{
	displayPage('content/content-gallery', array('dates' => getDates()));
}
else if($page == 'camera')
{
	displayPage('content/content-camera', array('ip' => IP, 'port' => PORT));
}
else
{
	displayPage('content/content-home', array());
}

?>
