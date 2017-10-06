<?php
function arctic_reports(){
  drupal_set_title(t('Arctic: Performance Overview'));

  return array(
    '#markup' => theme('arctic_reports'),
  );
}

function arctic_reports_rank(){
  drupal_set_title(t('Arctic: Rank Report'));

  return array(
    '#markup' => theme('arctic_reports_rank'),
  );
}

function arctic_reports_traffic(){
  drupal_set_title(t('Arctic: Traffic Detail'));

  return array(
    '#markup' => theme('arctic_reports_traffic'),
  );
}

function arctic_reports_leads(){
  drupal_set_title(t('Arctic: Leads Report'));

  return array(
    '#markup' => theme('arctic_reports_leads'),
  );
}

function arctic_seo(){
  drupal_set_title(t('Arctic: SEO Package'));

  return array(
    '#markup' => theme('arctic_seo'),
  );
}

function arctic_campaign(){
  drupal_set_title(t('Arctic: Campaign'));

  return array(
    '#markup' => theme('arctic_campaign'),
  );
}

function arctic_campaign_info(){
  drupal_set_title(t('White Fox Campaign Info'));

  return array(
    '#markup' => theme('arctic_campaign_info'),
  );
}

function arctic_campaign_launch(){
  drupal_set_title(t('White Fox Launch Formula'));

  return array(
    '#markup' => theme('arctic_campaign_launch'),
  );
}

function arctic_campaign_citations(){
  drupal_set_title(t('White Fox Citation Formula'));

  return array(
    '#markup' => theme('arctic_campaign_citations'),
  );
}

function arctic_campaign_onpage(){
  drupal_set_title(t('White Fox OnPage Formula'));

  return array(
    '#markup' => theme('arctic_campaign_onpage'),
  );
}

function arctic_campaign_maintenance(){
  drupal_set_title(t('White Fox Maintenance Tasks'));

  return array(
    '#markup' => theme('arctic_campaign_maintenance'),
  );
}

function arctic_deliverables(){
  drupal_set_title(t('Arctic: Deliverables Report'));

  return array(
    '#markup' => theme('arctic_deliverables'),
  );
}

function arctic_support(){
  drupal_set_title(t('Arctic: Changes & Support'));

  return array(
    '#markup' => theme('arctic_support'),
  );
}

function arctic_convert(){
  drupal_set_title(t('Arctic: Conversion strategy builder'));
  module_invoke('admin_menu', 'suppress');
  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');

  print theme('arctic_convert_builder');
  exit();
}

function arctic_convert_bar(){
  drupal_set_title(t('Arctic: Conversion strategy bar'));
  module_invoke('admin_menu', 'suppress');
  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');

  print theme('arctic_convert_bar');
  exit();
}

function arctic_convert_mat(){
  drupal_set_title(t('Arctic: Conversion strategy mat'));
  module_invoke('admin_menu', 'suppress');
  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');

  print theme('arctic_convert_mat');
  exit();
}

function arctic_convert_takeover(){
  drupal_set_title(t('Arctic: Conversion strategy takeover'));
  module_invoke('admin_menu', 'suppress');
  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');

  print theme('arctic_convert_takeover');
  exit();
}

function arctic_convert_slider(){
  drupal_set_title(t('Arctic: Conversion strategy slider'));
  module_invoke('admin_menu', 'suppress');
  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');

  print theme('arctic_convert_slider');
  exit();
}

function arctic_convert_dialog(){
  drupal_set_title(t('Arctic: Conversion strategy dialog'));
  module_invoke('admin_menu', 'suppress');
  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');

  print theme('arctic_convert_dialog');
  exit();
}

function arctic_convert_sidebar(){
  drupal_set_title(t('Arctic: Conversion strategy sidebar'));
  module_invoke('admin_menu', 'suppress');
  drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');

  print theme('arctic_convert_sidebar');
  exit();
}

include_once 'arctic.asana.api.inc';

function arctic_deliverables_json(){
  return drupal_json_output(_arctic_asana_obj_to_arr(_arctic_asana_get_project_deliverables()));
}

function arctic_site_json(){
  $out = db_select('variable', 'v')
  ->fields('v', array('name'))
  ->condition('name', db_like('site').'%', 'LIKE')
  ->execute()
  ->fetchAssoc();

  return drupal_json_output($out);
}
