<?php

	require_once('functions.php');
	
	if(getFile())
	{
		if(addTrack(getFile()))
		{
			displayAddPage('Lied wurde erfolgreich hinzugefuegt');
		}
		else
		{
			displayAddPage('Lied konnte nicht hinzugefuegt werden');
		}
	}
	else
	{
		displayViewPage();
	}
	
?>
