<?php
$arctic = drupal_get_path('module', 'arctic');

include_once "$arctic/inc/arctic.checklist.core.inc";

function arctic_campaign_citations_form(){
  $pre = 'arctic_campaign_citations__';

  $form = _arctic_checklist_form_settings(_arctic_checklist_form_assets($form), $pre, 'Listing');

  $form['citations'] = array(
    '#type' => 'container',
    'credentials' => array(
      '#title' => 'Default Credentials',
      '#type' => 'fieldset',
      $pre.'username' => array(
        '#type' => 'textfield',
        '#default_value' => variable_get($pre.'username', FALSE),
        '#attributes' => array(
          'placeholder' => 'username',
        ),
        '#prefix' => '<div class="col-md-4">',
        '#suffix' => '</div>',
      ),
      $pre.'email' => array(
        '#type' => 'textfield',
        '#default_value' => variable_get($pre.'username', FALSE),
        '#attributes' => array(
          'placeholder' => 'email',
        ),
        '#prefix' => '<div class="col-md-4">',
        '#suffix' => '</div>',
      ),
      $pre.'password' => array(
        '#type' => 'textfield',
        '#default_value' => variable_get($pre.'username', FALSE),
        '#attributes' => array(
          'placeholder' => 'password',
        ),
        '#prefix' => '<div class="col-md-4">',
        '#suffix' => '</div>',
      ),
      '#attributes' => array('class' => array('col-md-6', 'pull-right', 'text-right')),
      '#prefix' => '<div class="container-fluid"><div class="row">',
      '#suffix' => '</div></div>',
    ),
    'primary' => array(
      '#type' => 'fieldset',
      '#title' => 'Primary',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ),
    'social' => array(
      '#type' => 'fieldset',
      '#title' => 'Social',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ),
    'secondary' => array(
      '#type' => 'fieldset',
      '#title' => 'Secondary',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ),
    'tertiary' => array(
      '#type' => 'fieldset',
      '#title' => 'Tertiary',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    ),
  );

  $primary = &$form['citations']['primary'];
  $social = &$form['citations']['social'];
  $secondary = &$form['citations']['secondary'];
  $tertiary = &$form['citations']['tertiary'];
  
  
  
  return arctic_checklist_form($form);
}