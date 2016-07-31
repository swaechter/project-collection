<!DOCTYPE html>
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="description" content="WebCMS">
		<meta name="keywords" content="WebCMS">
		<meta name="author" content="Simon Waechter">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<script type="text/javascript" src="/webcms/static/scripts/jquery-2.1.4.min.js"></script>
		<script type="text/javascript" src="/webcms/static/scripts/bootstrap.min.js"></script>
		<script type="text/javascript" src="/webcms/static/scripts/script.js"></script>
		<link rel="stylesheet" href="/webcms/static/styles/bootstrap.min.css">
		<link rel="stylesheet" href="/webcms/static/styles/style.css">
		<title>WebCMS</title>
	</head>
	<body>
		<div class="container-fluid">
			<div class="banner img-rounded">
				<img class="img-responsive img-rounded" src="/webcms/static/images/banner.png" alt="Fehlendes Bild">
			</div>
			<div class="header navbar navbar-default img-rounded" role="navigation">
				<div class="navbar-header">
					<button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#navigation">
						<span class="icon-bar"></span>
						<span class="icon-bar"></span>
						<span class="icon-bar"></span>
					</button>
				</div>
				<div class="collapse navbar-collapse" id="navigation">
					<ul class="nav navbar-nav">
						<li><a href="/webcms">Home</a></li>
						<li><a href="/webcms/text/index">Text</a></li>
						<li><a href="/webcms/user/index">Admin</a></li>
					</ul>
				</div>
			</div>
			<div class="content img-rounded">
				<@layout.block name="content">
					<h1>Error</h1>
					<p>An unknown error occured!</p>
				</@layout.block>
			</div>
			<div class="footer navbar navbar-default navbar-bottom img-rounded">
				<p class="navbar-text"><b>WebCMS</b> von Simon Waechter <a href="https://github.com/swaechter/webcms">Sourcecode</a></p>
			</div>
		</div>
	</body>
</html>
