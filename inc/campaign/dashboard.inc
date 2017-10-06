<?php
require_once(drupal_get_path('module', 'arctic').'lib/drive/vendor/autoload.php');
require_once(drupal_get_path('module', 'arctic').'lib/sheets/vendor/autoload.php');

function arctic_drive_search_files($q = false, $settings = false){
  $client = arctic_gapi_get_client();

  $service = new Google_Service_Drive($client);

  if($q){$options['q'] = $q;}

  $options['fields'] = 'nextPageToken, files(id, name)';
  
  if($settings){$options = array_merge($options, $settings);}

  $results = $service->files->listFiles($options);

  $files = $results->getFiles();

  $out = FALSE;

  if(count($files) > 0)){
    $out = $files;
  }
  
  if($out && count($out) == 1){
    $out = $out[0];
  }

  return $out;
}

function arctic_gapi_get_client($settings = array(
  'creds' => 'drive-php-quickstart.json',
  'app' => 'Drive API PHP Quickstart',
  'scopes' => array(
    Google_Service_Drive::DRIVE_METADATA_READONLY
  ),
  'secret' => drupal_get_path('module', 'arctic').'lib/drive/client_secret.json'
)){
  extract($settings);
  
  $client = FALSE;
  
  $credentials_path = arctic_expand_home_directory("~/.credentials/$creds");
  
  if(file_exists($credentials_path)){
    $client = new Google_Client();
    
    $client->setApplicationName($app);
    
    $client->setScopes(implode(' ', $scopes));
    
    $client->setAuthConfig($secret);
    
    $client->setAccessType('offline');
    
    $access_token = json_decode(file_get_contents($credentials_path), true);
    
    $client->setAccessToken($access_token);
    
    if($client->isAccessTokenExpired()){
      $client->fetchAccessTokenWithRereshToken($client->getRefreshToken());
      
      file_put_contents($credentials_path, json_encode($client->getAccessToken()));
    }
  }
  
  return $client;
}

function arctic_expand_home_directory($path){
  $home_directory = getenv('HOME');

  if(empty($home_directory)){
    $home_directory = getenv('HOMEDRIVE') . getenv('HOMEPATH');
  }

  return str_replace('~', realpath($home_directory), $path);
}
