<?php
function arctic_menu(){
  $path = drupal_get_path('module', 'arctic');

  $inc = "$path/inc";

  $pages = 'arctic.pages.inc';

  $items['admin/arctic'] = array(
    'title' => 'Arctic',
    'page title' => 'Arctic: Performance Overview',
    'page callback' => 'arctic_reports',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic overview'),
    'description' => 'View Arctic Reports.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_NORMAL_ITEM,
    'weight' => -5000,
  );

  $items['admin/arctic/reports'] = array(
    'title' => 'Arctic',
    'page title' => 'Arctic: Performance Overview',
    'page callback' => 'arctic_reports',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic overview'),
    'description' => 'View Arctic Reports.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_DEFAULT_LOCAL_TASK,
    'weight' => 0,
  );

  $items['admin/arctic/rank'] = array(
    'title' => 'Rank',
    'page title' => 'Arctic: Rank Report',
    'page callback' => 'arctic_reports_rank',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic reports rank'),
    'description' => 'View Arctic rank report.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 1,
  );

  $items['admin/arctic/traffic'] = array(
    'title' => 'Traffic',
    'page title' => 'Arctic: Traffic Detail',
    'page callback' => 'arctic_reports_traffic',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic reports traffic'),
    'description' => 'View Arctic traffic report.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 2,
  );

  $items['admin/arctic/leads'] = array(
    'title' => 'Leads',
    'page title' => 'Arctic: Leads Report',
    'page callback' => 'arctic_reports_leads',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic reports leads'),
    'description' => 'View Arctic leads report.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 3,
  );

  $items['admin/arctic/seo'] = array(
    'title' => 'On Page SEO',
    'page title' => 'Arctic: SEO Package',
    'page callback' => 'arctic_seo',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic SEO.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 4,
  );

  $items['admin/arctic/campaign'] = array(
    'title' => 'Campaign',
    'page title' => 'Arctic: Campaign',
    'page callback' => 'arctic_campaign',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic Campaign.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 5,
  );

  $items['admin/arctic/campaign/dashboard'] = array(
    'title' => 'Dashboard',
    'page title' => 'Arctic: Campaign Dashboard',
    'page callback' => 'arctic_campaign',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic Campaign Dashboard.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_DEFAULT_LOCAL_TASK,
    'weight' => -1,
  );

  $items['admin/arctic/campaign/info'] = array(
    'title' => 'Campaign Info',
    'page title' => 'White Fox Campaign Info',
    'page callback' => 'arctic_campaign_info',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic Campaign Info.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 1,
  );

  $items['admin/arctic/campaign/launch'] = array(
    'title' => 'Launch Formula',
    'page title' => 'White Fox Launch Formula',
    'page callback' => 'arctic_campaign_launch',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic Campaign Launch.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 2,
  );

  $items['admin/arctic/campaign/citations'] = array(
    'title' => 'Citation Formula',
    'page title' => 'White Fox Citation Formula',
    'page callback' => 'arctic_campaign_citations',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic Campaign Citations.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 3,
  );

  $items['admin/arctic/campaign/onpage'] = array(
    'title' => 'OnPage Formula',
    'page title' => 'White Fox OnPage Formula',
    'page callback' => 'arctic_campaign_onpage',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic Campaign OnPage Formula.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 6,
  );

  $items['admin/arctic/campaign/maintenance'] = array(
    'title' => 'Maintenance Tasks',
    'page title' => 'White Fox Maintenance Tasks',
    'page callback' => 'arctic_campaign_maintenance',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic Campaign Maintenance.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 7,
  );

  $items['admin/arctic/deliverables'] = array(
    'title' => 'Deliverables',
    'page title' => 'Arctic: Deliverables Report',
    'page callback' => 'arctic_deliverables',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic deliverables'),
    'description' => 'View Arctic deliverables reports.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 6,
  );

  $items['admin/arctic/support'] = array(
    'title' => 'Changes & Support',
    'page title' => 'Arctic: Changes & Support',
    'page callback' => 'arctic_support',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic support'),
    'description' => 'View Arctic support.',
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 7,
  );

  $items['admin/arctic/settings'] = array(
    'title' => 'Settings',
    'page title' => 'Arctic: Settings',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('arctic_admin_settings_form'),
    'access callback' => 'user_access',
    'access arguments' => array('configure arctic'),
    'description' => 'Configure Arctic.',
    'file' => 'arctic.admin.inc',
    'file path' => $inc,
    'type' => MENU_LOCAL_TASK,
    'weight' => 8,
  );

  $items['admin/arctic/site.json'] = array(
    'title' => 'json for site info',
    'page callback' => 'arctic_site_json',
    'delivery callback' => 'drupal_json_output',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic json'),
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_CALLBACK,
  );

  $items['admin/arctic/campaign/launch/analytics-accounts.json'] = array(
    'page callback' => 'arctic_ga_users_autocomplete',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic json'),
    'type' => MENU_CALLBACK,
  );

  $items['admin/arctic/asana/deliverables.json'] = array(
    'title' => 'json for arctic deliverables',
    'page callback' => 'arctic_deliverables_json',
    'delivery callback' => 'drupal_json_output',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic deliverables'),
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_CALLBACK,
  );

  $items['admin/arctic/convert/builder'] = array(
    'title' => 'Arctic Conversion strategy builder',
    'page callback' => 'arctic_convert',
    'delivery callback' => 'ajax_render',
    'access callback' => 'user_access',
    'access arguments' => array('access arctic overview'),
    'file' => $pages,
    'file path' => $inc,
    'type' => MENU_CALLBACK,
  );

  $list = explode(',', 'bar,mat,takeover,slider,dialog,sidebar');

  foreach($list as $key => $value){
    $items['admin/arctic/convert/builder/'.$value] = array(
      'title' => 'Arctic Conversion strategy builder',
      'page callback' => 'arctic_convert_'.$value,
      'delivery callback' => 'ajax_render',
      'access callback' => 'user_access',
      'access arguments' => array('access arctic overview'),
      'file' => $pages,
      'file path' => $inc,
      'type' => MENU_CALLBACK,
    );
  }

  return $items;
}
