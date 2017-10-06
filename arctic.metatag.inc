<?php
function arctic_metatag_config_default(){
  $configs = array();
  
  $configs['global'] = new stdClass();
  $configs['global']->disabled = FALSE;
  $configs['global']->api_version = 1;
  $configs['global']->instance = 'global';
  $configs['global']->config = array(
    'title' => array(
      'value' => '[current-page:title] | [current-page:pager][site:name]',
    ),
    'robots' => array(
      'value' => array(
        'index' => 0,
        'follow' => 0,
        'noindex' => 0,
        'nofollow' => 0,
        'noarchive' => 0,
        'nosnippet' => 0,
        'noodp' => 0,
        'noydir' => 0,
        'noimageindex' => 0,
        'notranslate' => 0,
      ),
    ),
    'rating' => array(
      'value' => 'general',
    ),
    'generator' => array(
      'value' => 'Digital Marketing by White Fox (https://whitefoxstudios.net/digital-marketing)',
    ),
    'rights' => array(
      'value' => '© Copyright [current-date:custom:Y] [company:name], All rights reserved',
    ),
    'image_src' => array(
      'value' => '[company:logo]',
    ),
    'canonical' => array(
      'value' => '[current-page:url:absolute]',
    ),
    'shortlink' => array(
      'value' => '[current-page:url:unaliased]',
    ),
    'publisher' => array(
      'value' => '[company:google_plus]',
    ),
    'author' => array(
      'value' => '[company:google_plus]',
    ),
    'geo.position' => array(
      'value' => '[company:lat];[company:long]',
    ),
    'geo.placename' => array(
      'value' => '[company:name]',
    ),
    'geo.region' => array(
      'value' => 'US-[company:state]',
    ),
    'icbm' => array(
      'value' => '[company:lat],[company:long]',
    ),
    'revisit-after' => array(
      'value' => '1',
      'period' => 'week',
    ),
    'og:site_name' => array(
      'value' => '[company:name]',
    ),
    'og:type' => array(
      'value' => 'company',
    ),
    'og:url' => array(
      'value' => '[current-page:url:absolute]',
    ),
    'og:title' => array(
      'value' => '[metatag:title]',
    ),
    'og:determiner' => array(
      'value' => 'auto',
    ),
    'og:description' => array(
      'value' => '[metatag:description]',
    ),
    'og:image' => array(
      'value' => '[company:logo]',
    ),
    'og:image:url' => array(
      'value' => '[company:logo]',
    ),
    'og:image:secure_url' => array(
      'value' => '[company:logo]',
    ),
    'og:image:type' => array(
      'value' => '[company:logo]',
    ),
    'og:image:width' => array(
      'value' => '[company:logo]',
    ),
    'og:image:height' => array(
      'value' => '[company:logo]',
    ),
    'og:latitude' => array(
      'value' => '[company:lat]',
    ),
    'og:longitude' => array(
      'value' => '[company:long]',
    ),
    'og:street_address' => array(
      'value' => '[company:street]',
    ),
    'og:locality' => array(
      'value' => '[company:city]',
    ),
    'og:region' => array(
      'value' => '[company:state]',
    ),
    'og:postal_code' => array(
      'value' => '[company:zip]',
    ),
    'og:country_name' => array(
      'value' => 'United States',
    ),
    'og:email' => array(
      'value' => '[company:email]',
    ),
    'og:phone_number' => array(
      'value' => '[company:phone]',
    ),
    'twitter:card' => array(
      'value' => 'summary_large_image',
    ),
    'twitter:site' => array(
      'value' => '[company:twitter]',
    ),
    'twitter:creator' => array(
      'value' => '[company:twitter]',
    ),
    'twitter:url' => array(
      'value' => '[current-page:url:absolute]',
    ),
    'twitter:title' => array(
      'value' => '[current-page:title]',
    ),
    'twitter:description' => array(
      'value' => '[metatag:description]',
    ),
    'twitter:image' => array(
      'value' => '[company:logo]',
    ),
    'twitter:image:width' => array(
      'value' => '[company:logo]',
    ),
    'twitter:image:height' => array(
      'value' => '[company:logo]',
    ),
    'twitter:image:alt' => array(
      'value' => '[metatag:title] [metatag:description] [metatag:keywords]',
    ),
  );
  
  $configs['node'] = new stdClass();
  $configs['node']->disabled = FALSE; 
  $configs['node']->api_version = 1;
  $configs['node']->instance = 'node';
  $configs['node']->config = array(
    'title' => array(
      'value' => '[node:field_page_title]',
    ),
    'description' => array(
      'value' => '[node:field_meta_description]',
    ),
    'image_src' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'og:updated_time' => array(
      'value' => '[node:changed:custom:c]',
    ),
    'og:image' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'og:image:url' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'og:image:secure_url' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'og:image:type' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'og:image:width' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'og:image:height' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'article:published_time' => array(
      'value' => '[node:created:custom:c]',
    ),
    'article:modified_time' => array(
      'value' => '[node:changed:custom:c]',
    ),
    'twitter:title' => array(
      'value' => '[metatag:title]',
    ),
    'twitter:image' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'twitter:image:width' => array(
      'value' => '[node:field_open_graph_image]',
    ),
    'twitter:image:height' => array(
      'value' => '[node:field_open_graph_image]',
    ),
  );
  
  $disabled = array(
    'global:frontpage',
    'global:403',
    'global:404',
    'taxonomy',
    'user',
  );
  
  foreach($disabled as $config){
    $configs[$config] = new stdClass();
    $configs[$config]->disabled = TRUE; 
    $configs[$config]->api_version = 1;
    $configs[$config]->instance = $config;
  }
  
  return $configs;
}
