<?php

require('functions.php');

$request = getRequest();

if($request == 'select-day')
{
	if(isPVar('select-day'))
	{
		displayReplyPage('replies/reply-gallery', array('images' => getHours(getPVar('select-day'))));
	}
}
else if($request == 'send-request')
{
	if(isPVar('input-username'))
	{
		addUserToQueue(getPVar('input-username'));
		displayReplyPage('replies/reply-camera-queue', array('queue' => getQueueItems()));
	}
	else
	{
		displayErrorBox("Please enter a valid username.");
	}
}
else if($request == 'get-queue')
{
	updateQueue();
	displayReplyPage('replies/reply-camera-queue', array('queue' => getQueueItems()));
}
else if($request == 'check-queue')
{
	displayArray(getQueueUserCheck());
}
else if($request == 'enable-camera')
{
	displayReplyPage('replies/reply-camera-view', array('ip' => IP, 'port' => PORT));
}
else if($request == 'disable-camera')
{
	removeUserFromQueue();
	displayErrorBox("Your camera session has expired. To request a new one reload the site or navigate to the camera section");
}
else if($request == 'move-camera-left')
{
	sendCommand(MOVE_LEFT);
}
else if($request == 'move-camera-up')
{
	sendCommand(MOVE_UP);
}
else if($request == 'move-camera-down')
{
	sendCommand(MOVE_DOWN);
}
else if($request == 'move-camera-right')
{
	sendCommand(MOVE_RIGHT);
}
else
{
	displayErrorBox("Invalid request.");
}

?>
