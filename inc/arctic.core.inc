<?php
function _arctic_get_default_lib(){
  $path = current_path();

  if(!path_is_admin($path)){
    drupal_add_js('https://s12.in:4243/socket.io/socket.io.js', array(
      'type' => 'external',
      'scope' => 'footer',
      'group' => JS_THEME,
      'weight' => 90000,
    ));

    drupal_add_js(drupal_get_path('module', 'arctic') .'/js/goals.js', array(
      'type' => 'file',
      'scope' => 'footer',
      'group' => JS_THEME,
      'every_page' => true,
      'weight' => 99999,
      'requires_jquery' => true,
      'defer' => true,
      'cache' => false,
      'preprocess' => false,
    ));
  }

  if(preg_match('/admin\/arctic/', $path)){
    drupal_add_css('https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css', array(
      'type' => 'external',
      'group' => CSS_THEME,
      'weight' => -50003,
    ));

    drupal_add_css('https://fonts.googleapis.com/icon?family=Material+Icons', array(
      'type' => 'external',
      'group' => CSS_THEME,
      'weight' => -50002,
    ));

    drupal_add_css('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css', array(
      'type' => 'external',
      'group' => CSS_THEME,
      'weight' => -50001,
    ));

    drupal_add_css('https://storage.googleapis.com/code.getmdl.io/1.0.6/material.blue_grey-light_blue.min.css', array(
      'type' => 'external',
      'group' => CSS_THEME,
      'weight' => -50000,
    ));

    drupal_add_css(drupal_get_path('module', 'arctic') .'/css/arctic.css', array(
      'group' => CSS_THEME,
      'weight' => 50005,
    ));

    drupal_add_css(drupal_get_path('module', 'arctic') .'/css/mdl-color.css', array(
      'group' => CSS_THEME,
      'weight' => 50006,
    ));

    drupal_add_js('https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js', array(
      'type' => 'external',
      'scope' => 'footer',
      'group' => JS_THEME,
      'weight' => 50000,
    ));

    drupal_add_js('https://storage.googleapis.com/code.getmdl.io/1.0.6/material.min.js', array(
      'type' => 'external',
      'scope' => 'footer',
      'group' => JS_THEME,
      'weight' => 50001,
    ));

    drupal_add_js(drupal_get_path('module', 'arctic') .'/js/arctic.js', array(
      'scope' => 'footer',
      'group' => JS_THEME,
      'weight' => 50002,
    ));

    $prt_token = variable_get('arctic_prt_token', '10227-XKYNU7E2MIOI');
    $prt_site = urlencode(variable_get('arctic_prt_site', $GLOBALS['base_url']));
    $prt_url = "https://proranktracker.com/ext/?t=$prt_token&s=$prt_site";

    drupal_add_js(array(
      'arctic' => array(
        'prt_url' => $prt_url,
      ),
    ), 'setting');

    drupal_add_js(drupal_get_path('module', 'arctic') .'/js/rank.js', array(
      'type' => 'file',
      'scope' => 'footer',
      'group' => JS_THEME,
      'weight' => 50003,
    ));
  }

  switch ($path) {
    case 'admin/arctic/reports':
      break;

    case 'admin/arctic/rank':
      drupal_add_css('iframe#prt{width:100%}', 'inline');

      drupal_add_js(drupal_get_path('module', 'arctic') .'/js/iframeResizer.min.js', array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
        'weight' => 50003,
      ));

      drupal_add_js('(function($){$(document).ready(function(e){iFrameResize(); $(window).on(\'resize\', function(e){iFrameResize();});});})(jQuery);', array(
        'type' => 'inline',
        'scope' => 'footer',
        'group' => JS_THEME,
        'weight' => 50004,
      ));

      break;

    case 'admin/arctic/traffic':
      break;

    case 'admin/arctic/leads':
      break;

    case 'admin/arctic/seo':
      break;

    case 'admin/arctic/deliverables':
      drupal_add_js(array(
        'arctic' => array(
          'asana_api_key' => variable_get('arctic_asana_api_key', '0/d0ab7d6cb7d5fb1fa5d8c817e8e98a27'),
          'asana_project_id' => variable_get('arctic_asana_project', false),
        ),
      ), 'setting');

      drupal_add_js(drupal_get_path('module', 'arctic') .'/js/asana.js', array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
        'weight' => 60000,
      ));

      drupal_add_js(drupal_get_path('module', 'arctic') .'/js/asana.deliverables.js', array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
        'weight' => 70000,
      ));

      break;

    case 'admin/arctic/support':
      drupal_add_css('iframe#freshwidget-embedded-form{width:100%}', 'inline');

      drupal_add_js(drupal_get_path('module', 'arctic') .'/js/iframeResizer.min.js', array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
        'weight' => 50003,
      ));

      drupal_add_js('(function($){$(document).ready(function(e){iFrameResize(); $(window).on(\'resize\', function(e){iFrameResize();});});})(jQuery);', array(
        'type' => 'inline',
        'scope' => 'footer',
        'group' => JS_THEME,
        'weight' => 50004,
      ));

      break;
    case 'admin/arctic/convert/builder':
      drupal_add_css(drupal_get_path('module', 'arctic') .'/css/convert-builder.css', array(
        'group' => CSS_THEME,
        'weight' => 50006,
      ));

      drupal_add_js(drupal_get_path('module', 'arctic') .'/js/jquery.responsiveiframe.js', array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
        'weight' => -60000,
      ));

      drupal_add_js(drupal_get_path('module', 'arctic') .'/js/convert-builder.js', array(
        'type' => 'file',
        'scope' => 'footer',
        'group' => JS_THEME,
        'weight' => 60001,
      ));
      break;
  }
}

// implementation of hook_url_inbound_alter()
function arctic_url_inbound_alter(&$path, $original_path, $path_language){
  // ensure vars from query string exist in $_GET
  // this is needed for URL Aliases with query components to work properly
  parse_str( parse_url( $path, PHP_URL_QUERY ), $vars );
  foreach( $vars as $key => $value ){
    // don't overwrite existing values (ie from the actual URL)
    if( !array_key_exists( $key, $_GET ) ){
      $_GET[$key] = $value;
    }
  }
}
