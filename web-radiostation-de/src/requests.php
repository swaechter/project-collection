<?php

require_once('functions.php');

if(getRequest() == 'view')
{
	echo json_encode(getTracks());
}
else if(getRequest() == 'search')
{
	$jsontracks = array();
	if(getPlayDate())
	{
		foreach(getTracks() as $track)
		{
			if(strpos($track['playdate'], getPlayDate()) !== false)
			{
				$jsontracks[] = $track;
			}
		}
	}
	echo json_encode($jsontracks);
}
else
{
	jsonecho('error', 'Ungueltiger Request');
}

?>
