<?php

define('MYSQL_HOST', '127.0.0.1');
define('MYSQL_USER', 'root');
define('MYSQL_PASSWORD', '');
define('MYSQL_DATABASE', 'panoramaview');

define('IP', '10.142.126.225');
define('PORT', '554');
define('MOVE_HOME', 'http://' . IP . '/cgi-bin/camctrl.cgi?move=home');
define('MOVE_LEFT', 'http://' . IP . '/cgi-bin/camctrl.cgi?move=left');
define('MOVE_UP', 'http://' . IP . '/cgi-bin/camctrl.cgi?move=up');
define('MOVE_DOWN', 'http://' . IP . '/cgi-bin/camctrl.cgi?move=down');
define('MOVE_RIGHT', 'http://' . IP . '/cgi-bin/camctrl.cgi?move=right');
define('GET_STREAM', 'rtsp://' . IP . '/live.sdp');
define('GET_IMAGE', 'http://' . IP . '/cgi-bin/video.jpg');

define('DATA', 'data/');
define('IMAGE_NAME_INPUT', DATA . 'input_');
define('IMAGE_NAME_OUTPUT', DATA . 'output_');
define('IMAGE_TYPE', '.jpg');
define('IMAGE_COUNT', '5');
define('IMAGE_X', '640');
define('IMAGE_Y', '480');
define('IMAGE_BORDER' , '25');

?>
