<?php
  $arctic_path = drupal_get_path('module', 'arctic');

  include_once "$arctic_path/inc/convert-builder.inc";
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
<link href="https://cdn8.s12.in/<?php print $arctic_path; ?>/css/convert-builder.css" rel="stylesheet">
</head>

<body>
<div class="mdl-layout mdl-js-layout mdl-layout--fixed-header mdl-layout--fixed-tabs">
  <header class="mdl-layout__header">
    <div class="mdl-layout__tab-bar mdl-js-ripple-effect">
      <a href="#convert_builder-view" class="mdl-layout__tab is-active">View</a>

      <a href="#convert_builder-edit" class="mdl-layout__tab">Edit</a>

      <a href="#convert_builder-create" class="mdl-layout__tab">Create</a>
    </div>
  </header>

  <main class="mdl-layout__content">
    <section id="convert_builder-view" class="mdl-layout__tab-panel is-active">
      <div class="page-content"><!-- Your content goes here --></div>
    </section>

    <section id="convert_builder-edit" class="mdl-layout__tab-panel">
      <div class="page-content"><!-- Your content goes here --></div>
    </section>

    <section id="convert_builder-create" class="mdl-layout__tab-panel">
      <div class="page-content">
        <?php
          $arctic_convert_builder_create_form = drupal_get_form('arctic_convert_builder_create_form');

          print drupal_render($arctic_convert_builder_create_form);
        ?>
      </div>
    </section>
  </main>
</div>

<script defer src="https://code.jquery.com/jquery-1.12.4.min.js"></script>
<script defer src="https://code.jquery.com/jquery-migrate-1.2.1.min.js"></script>

<script defer src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
<script defer src="https://code.getmdl.io/1.1.3/material.min.js"></script>
<script defer src="https://cdn7.s12.in/<?php print $arctic_path; ?>/js/jquery.responsiveiframe.js"></script>

<script defer src="https://cdn6.s12.in/<?php print $arctic_path; ?>/js/convert-builder.js"></script>
</body>
</html>
