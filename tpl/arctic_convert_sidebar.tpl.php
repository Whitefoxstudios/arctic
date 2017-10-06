<?php
  $arctic_path = drupal_get_path('module', 'arctic');
?>
<!doctype html>
<!--[if lt IE 9]><html lang="us" class="no-js lt-ie10 lt-ie9"><![endif]--><!--[if lt IE 10]><html lang="us" class="no-js lt-ie10"><![endif]--><!--[if gte IE 10]><!--><html lang="us" class="no-js"><!--<![endif]-->
<head>
<meta name="apple-mobile-web-app-capable" content="yes">
<meta name="viewport" content="user-scalable=no,initial-scale=1.0,maximum-scale=1.0,width=device-width,minimal-ui">
<meta name="HandheldFriendly" content="True">
<meta name="MobileOptimized" content="320">

<title><?php print drupal_get_title(); ?></title>

<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css" rel="stylesheet">
<link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" rel="stylesheet">
<link href="https://code.getmdl.io/1.1.3/material.purple-green.min.css" rel="stylesheet">

<link href="https://cdn9.s12.in/<?php print $arctic_path; ?>/css/mdl-color.css" rel="stylesheet">
<link href="https://cdn8.s12.in/<?php print $arctic_path; ?>/css/convert.css" rel="stylesheet">
</head>

<body class="convert sidebar">
<div class="convert-body-inner">
  <div id="cb--sidebar" class="convert-wrapper text-center">
    <div class="convert-inner">
      <h1 class="convert-title">Your title</h1>
      <p class="convert-message lead">Your Message here.</p>
      <p class="convert-buttons"><a href="#" class="convert-button-primary mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--colored">Call to action</a> <a href="#" class="convert-button-secondary mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--accent">Alternate option</a></p>
    </div>
  </div>
</div>

<script defer src="https://code.jquery.com/jquery-1.12.4.min.js"></script>
<script defer src="https://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>

<script defer src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
<script defer src="https://code.getmdl.io/1.1.3/material.min.js"></script>
<script defer src="https://cdn7.s12.in/<?php print $arctic_path; ?>/js/jquery.responsiveiframe.js"></script>

<script defer src="https://cdn6.s12.in/<?php print $arctic_path; ?>/js/convert.js"></script>
</body>
</html>
