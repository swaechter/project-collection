<?php

require_once('functions.php');

$request = getRequest(); // Get the request and check if it is a valid one

if($request == 'local-camera-state')
{
	if(getPVar("selectlocalcamerastate") != "-")
	{
		if(setCameraMode(getPVar("selectlocalcamerastate")))
		{
			displaySuccessBox("Camera mode set");
		}
		else
		{
			displayErrorBox("Cannot set camera mode");
		}
	}
	else
	{
		displayErrorBox("Missing camera state.");
	}
}
else if($request == 'local-camera-stream')
{
	streamCamera(getCameraIpWithPort());
}
else if($request == 'local-camera-video')
{
	if(getPVar("selectlocalcameramonitoring") != '-')
	{
		streamVideo(getPVar("selectlocalcameramonitoring"));
	}
	else
	{
		displayErrorBox("Missing video.");
	}
}
else if($request == 'remote-cameras-add')
{
	if(isPVar("inputaddremotecamera"))
	{
		addRemoteCamera(getPVar("inputaddremotecamera"));
		displaySuccessBox("Camera added.");
	}
	else
	{
		displayErrorBox("Missing IP address.");
	}
}
else if($request == 'remote-cameras-remove')
{
	if(getPVar("selectremoveremotecamera") != "-")
	{
		removeRemoteCamera(getPVar("selectremoveremotecamera"));
		displaySuccessBox("Camera removed.");
	}
	else
	{
		displayErrorBox("Missing camera.");
	}
}
else if($request == 'remote-cameras-stream')
{
	if(getPVar("selectseeremotestream") != "-")
	{
		streamCamera(getPVar("selectseeremotestream"));
	}
	else
	{
		displayErrorBox("Missing camera.");
	}
}
else // Or an error, because the request does not exist
{
	displayErrorBox("Invalid request.");
}

?>
