<?php
function arctic_views_default_views(){
  $files = file_scan_directory(drupal_get_path('module', 'arctic'). '/views', '/\.view/');
  
  foreach ($files as $absolute => $file) {
    require $absolute;
    if (isset($view)) {
      $views[$file->name] = $view;
    }   
  }
  
  return $views;
}
