<?php
function arctic_admin_settings_form(){
  $form['#attached'] = array(
    'js' => array(
      '//cdnjs.cloudflare.com/ajax/libs/chosen/1.5.1/chosen.jquery.min.js' => array(
        'type' => 'external',
      ),
      '(function($){
        $(document).ready(function(e){
          $(".chosen").chosen({no_results_text: "Oops, nothing found!"});
        });
      })(jQuery)' => array(
        'type' => 'inline',
      ),
    ),
    
    'css' => array(
      '//cdnjs.cloudflare.com/ajax/libs/chosen/1.5.1/chosen.min.css' => array(
        'type' => 'external',
      ),
    ),
  );
  
  $form['campaign'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="row">',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('unstyled')),
  );

  $form['campaign']['company'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="col-md-6">',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('unstyled')),
  );

  $form['campaign']['company']['info'] = array(
    '#type' => 'fieldset',
    '#title' => 'Contact Info',
    '#attributes' => array('class' => array('styled')),
  );

  $form['campaign']['company']['info']['arctic_name'] = array(
    '#type' => 'textfield',
    '#title' => 'Name',
    '#description' => 'Same as Google My Business name.',
    '#default_value' => variable_get('arctic_name', variable_get('site_name', false)),
  );
  
  $form['campaign']['company']['info']['address'] = array(
    '#type' => 'fieldset',
    '#title' => 'Address',
    '#attributes' => array('class' => array('unstyled')),
  );

  $form['campaign']['company']['info']['address']['arctic_address_street'] = array(
    '#type' => 'textfield',
    '#title' => 'Street',
    '#default_value' => variable_get('arctic_address_street', false),
  );

  $form['campaign']['company']['info']['address']['arctic_address_city'] = array(
    '#type' => 'textfield',
    '#title' => 'City',
    '#default_value' => variable_get('arctic_address_city', false),
    '#prefix' => '<div class="row"><div class="col-md-6">',
    '#suffix' => '</div>',
  );

  $form['campaign']['company']['info']['address']['arctic_address_state'] = array(
    '#type' => 'textfield',
    '#title' => 'State',
    '#default_value' => variable_get('arctic_address_state', false),
    '#maxlength' => 2,
    '#size' => 4,
    '#prefix' => '<div class="col-md-2">',
    '#suffix' => '</div>',
  );

  $form['campaign']['company']['info']['address']['arctic_address_zip'] = array(
    '#type' => 'textfield',
    '#title' => 'Zip',
    '#default_value' => variable_get('arctic_address_zip', false),
    '#maxlength' => 5,
    '#size' => 10,
    '#prefix' => '<div class="col-md-4">',
    '#suffix' => '</div></div>',
  );

  $form['campaign']['company']['info']['arctic_phone'] = array(
    '#type' => 'textfield',
    '#title' => 'Phone',
    '#description' => '828-246-9552',
    '#maxlength' => 12,
    '#size' => 24,
    '#default_value' => variable_get('arctic_phone', false),
    '#prefix' => '<div class="row"><div class="col-md-4">',
    '#suffix' => '</div>',
  );

  $form['campaign']['company']['info']['arctic_email'] = array(
    '#type' => 'emailfield',
    '#title' => 'Email',
    '#default_value' => variable_get('arctic_email', false),
    '#prefix' => '<div class="col-md-8">',
    '#suffix' => '</div></div>',
  );

  $form['campaign']['company']['info']['arctic_hours'] = array(
    '#type' => 'textarea',
    '#title' => 'Hours',
    '#description' => "One set per line (schema) format eg.<pre><code>Tu - Su 11:00 - 14:00\n Tu - Su 16:00 - 22:00</code></pre>",
    '#default_value' => variable_get('arctic_hours', 'Mo - Fr 9:00 - 17:00'),
  );

  $form['campaign']['company']['info']['arctic_area_served'] = array(
    '#type' => 'textarea',
    '#title' => 'Area Served',
    '#description' => "One per line (schema) format eg.<pre><code>Asheville, NC\n Greenville, SC</code></pre>",
    '#default_value' => variable_get('arctic_area_served', false),
  );

  $form['campaign']['company']['social'] = array(
    '#type' => 'fieldset',
    '#title' => 'Social',
    '#attributes' => array('class' => array('styled')),
  );
  
  $form['campaign']['company']['social']['arctic_social_facebook'] = array(
    '#type' => 'textfield',
    '#title' => 'Facebook',
    '#default_value' => variable_get('arctic_social_facebook', false),
    '#prefix' => '<div class="social facebook">',
    '#suffix' => '</div>',
  );
  
  $form['campaign']['company']['social']['arctic_social_googleplus'] = array(
    '#type' => 'textfield',
    '#title' => 'Google+',
    '#default_value' => variable_get('arctic_social_googleplus', false),
    '#prefix' => '<div class="social googleplus">',
    '#suffix' => '</div>',
  );
  
  $form['campaign']['company']['social']['arctic_social_instagram'] = array(
    '#type' => 'textfield',
    '#title' => 'Instagram',
    '#default_value' => variable_get('arctic_social_instagram', false),
    '#prefix' => '<div class="social instagram">',
    '#suffix' => '</div>',
  );
  
  $form['campaign']['company']['social']['arctic_social_linkedin'] = array(
    '#type' => 'textfield',
    '#title' => 'LinkedIn',
    '#default_value' => variable_get('arctic_social_linkedin', false),
    '#prefix' => '<div class="social linkedin">',
    '#suffix' => '</div>',
  );
  
  $form['campaign']['company']['social']['arctic_social_pinterest'] = array(
    '#type' => 'textfield',
    '#title' => 'Pinterest',
    '#default_value' => variable_get('arctic_social_pinterest', false),
    '#prefix' => '<div class="social pinterest">',
    '#suffix' => '</div>',
  );
  
  $form['campaign']['company']['social']['arctic_social_twitter'] = array(
    '#type' => 'textfield',
    '#title' => 'Twitter',
    '#default_value' => variable_get('arctic_social_twitter', false),
    '#prefix' => '<div class="social twitter">',
    '#suffix' => '</div>',
  );
  
  $form['campaign']['company']['social']['arctic_social_youtube'] = array(
    '#type' => 'textfield',
    '#title' => 'YouTube',
    '#default_value' => variable_get('arctic_social_youtube', false),
    '#prefix' => '<div class="social youtube">',
    '#suffix' => '</div>',
  );
  
  $form['campaign']['seo'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="col-md-6">',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('unstyled')),
  );

  $form['campaign']['seo']['accounts'] = array(
    '#type' => 'fieldset',
    '#title' => 'Account Emails',
    '#attributes' => array('class' => array('styled')),
  );

  $form['campaign']['seo']['accounts']['arctic_accounts_gmb'] = array(
    '#type' => 'textfield',
    '#title' => 'Google My Business',
    '#default_value' => variable_get('arctic_accounts_gmb', false),
  );

  $form['campaign']['seo']['accounts']['arctic_accounts_ga'] = array(
    '#type' => 'textfield',
    '#title' => 'Analytics',
    '#default_value' => variable_get('arctic_accounts_ga', false),
  );

  $form['campaign']['seo']['accounts']['arctic_accounts_gsc'] = array(
    '#type' => 'textfield',
    '#title' => 'Search Console',
    '#default_value' => variable_get('arctic_accounts_gsc', false),
  );

  $form['campaign']['seo']['accounts']['arctic_accounts_adwords'] = array(
    '#type' => 'textfield',
    '#title' => 'AdWords',
    '#default_value' => variable_get('arctic_accounts_adwords', false),
  );

  $form['campaign']['seo']['gmb'] = array(
    '#type' => 'fieldset',
    '#title' => 'Google My Business',
    '#attributes' => array('class' => array('styled')),
  );

  $form['campaign']['seo']['gmb']['arctic_gmb_name'] = array(
    '#type' => 'textfield',
    '#title' => 'Name',
    '#default_value' => variable_get('arctic_gmb_name', variable_get('site_name', false)),
  );

  $form['campaign']['seo']['gmb']['arctic_gmb_place'] = array(
    '#type' => 'textfield',
    '#title' => 'Places URL',
    '#default_value' => variable_get('arctic_gmb_place', false),
  );

  $form['campaign']['seo']['gmb']['arctic_google_plus'] = array(
    '#type' => 'textfield',
    '#title' => 'G+ URL',
    '#default_value' => variable_get('arctic_google_plus', false),
  );

  $form['campaign']['seo']['gmb']['arctic_youtube_url'] = array(
    '#type' => 'textfield',
    '#title' => 'YouTube URL',
    '#default_value' => variable_get('arctic_youtube_url', false),
  );

  $form['campaign']['seo']['info'] = array(
    '#type' => 'fieldset',
    '#title' => 'SEO',
    '#attributes' => array('class' => array('styled')),
  );

  $form['campaign']['seo']['info']['arctic_keywords'] = array(
    '#type' => 'textarea',
    '#title' => 'Keywords',
    '#description' => 'One Per Line',
    '#default_value' => variable_get('arctic_keywords', false),
  );

  $form['campaign']['seo']['info']['arctic_categories'] = array(
    '#type' => 'textarea',
    '#title' => 'Categories',
    '#description' => 'One Per Line',
    '#default_value' => variable_get('arctic_categories', false),
  );
  
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => 'Advanced',
    '#description' => '(Use with caution) This form will alter the behavior of Arctic.',
    '#prefix' => '<div class="row row-flex-md row-flex-lg">',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('unstyled')),
  );

  $form['advanced']['prt'] = array(
    '#type' => 'fieldset',
    '#title' => 'Rank tracking',
    '#prefix' => '<div class="col-md-6">',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('styled')),
  );

  $form['advanced']['prt']['arctic_prt_token'] = array(
    '#type' => 'textfield',
    '#title' => 'Token',
    '#default_value' => variable_get('arctic_prt_token', '10227-XKYNU7E2MIOI'),
  );

  $form['advanced']['prt']['arctic_prt_site'] = array(
    '#type' => 'textfield',
    '#title' => 'Site',
    '#default_value' => variable_get('arctic_prt_site', $GLOBALS['base_url']),
  );

  $form['advanced']['asana'] = array(
    '#type' => 'fieldset',
    '#title' => 'Project Management',
    '#prefix' => '<div class="col-md-6">',
    '#suffix' => '</div>',
    '#attributes' => array('class' => array('styled')),
  );

  $form['advanced']['asana']['arctic_asana_api_key'] = array(
    '#type' => 'textfield',
    '#title' => 'Asana API Key',
    '#default_value' => variable_get('arctic_asana_api_key', '0/d0ab7d6cb7d5fb1fa5d8c817e8e98a27'),
  );
  
  include_once drupal_get_path('module', 'arctic').'/inc/arctic.asana.api.inc';

  $form['advanced']['asana']['arctic_asana_project'] = array(
    '#type' => 'select',
    '#title' => 'Asana Project',
    '#options' => _arctic_asana_get_projects_options(),
    '#default_value' => variable_get('arctic_asana_project', NULL),
    '#required' => TRUE,
    '#attributes' => array('class' => array('chosen')),
  );

  return system_settings_form($form);
}
