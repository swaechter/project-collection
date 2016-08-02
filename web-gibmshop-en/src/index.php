<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" href="<?php echo $this->baseurl ?>/templates/<?php echo $this->template; ?>/styles/style.css"/>
	</head>
	<body>
		<div class="header">
		</div>
		<div class="container">
			<div class="banner">
				<img src="<?php echo $this->baseurl ?>/templates/<?php echo $this->template; ?>/images/banner.png" alt="Error"/>
			</div>
			<div class="navigation">
				<div class="navigation-logo">
					<img src="<?php echo $this->baseurl ?>/templates/<?php echo $this->template; ?>/images/logo.png" alt="Error"/>
				</div>
				<div class="navigation-navigation">
					<img src="<?php echo $this->baseurl ?>/templates/<?php echo $this->template; ?>/images/navigation.png" alt="Error"/>
				</div>
				<div class="navigation-content">
					<jdoc:include type="modules" name="position-7"/>
				</div>
			</div>
			<div class="content">
				<jdoc:include type="modules" name="position-3"/>
				<jdoc:include type="message"/>
				<jdoc:include type="component"/>
				<jdoc:include type="modules" name="position-2"/>
			</div>
			<div style="clear: both;"></style>
		</div>
	</body>
</html>
