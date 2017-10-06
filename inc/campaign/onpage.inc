<?php
function arctic_campaign_traffic_form(){
  $arctic = drupal_get_path('module', 'arctic');
  
  $form['#attached']['css']['//cdnjs.cloudflare.com/ajax/libs/chosen/1.5.1/chosen.min.css']['type'] = 'external';
  $form['#attached']['css']["$arctic/css/checklist.css"]['type'] = 'file';
  
  $form['#attached']['js']['//cdnjs.cloudflare.com/ajax/libs/chosen/1.5.1/chosen.jquery.min.js']['type'] = 'external';
  $form['#attached']['js']["$arctic/js/checklist.js"]['type'] = 'file';
  
  $form['settings'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('row')),
  );
  
  $form['settings']['arctic_asana_project'] = array(
    '#type' => 'select',
    '#title' => 'Asana Project',
    '#empty_option' => ' - Choose Asana Project - ',
    '#options' => _arctic_asana_get_projects_options(),
    '#default_value' => variable_get('arctic_asana_project', NULL),
    '#required' => TRUE,
    '#attributes' => array('class' => array('chosen')),
    '#prefix' => '<div class="col-md-4">',
    '#suffix' => '</div>',
  );
  
  $pre = 'arctic_campaign_traffic__';
  
  $form['settings'][$pre.'working_agent'] = array(
    '#type' => 'select',
    '#title' => 'Working Agent',
    '#empty_option' => ' - Choose Agent - ',
    '#options' => array(
      'benji' => 'Benji',
      'byron' => 'Byron',
      'michael' => 'Michael',
      'jd' => 'JD'
    ),
    '#default_value' => variable_get($pre.'working_agent', NULL),
    '#required' => TRUE,
    '#attributes' => array('class' => array('chosen')),
    '#prefix' => '<div class="col-md-4">',
    '#suffix' => '</div>',
  );

  $form['file_customer_info'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('row checklist-item')),
    '#tree' => TRUE,
    
    $pre.'file_customer_info__status' => array(
      '#type' => 'checkbox',
      '#title' => 'File Customer Info',
      '#default_value' => variable_get($pre.'file_customer_info__status', 0),
      '#prefix' => '<div class="col-md-4 fancy">',
      '#suffix' => '</div>',
      '#field_suffix' => '<svg class="checkmark'.((variable_get($pre.'file_customer_info__status', 0) == 1) ? ' checked' : '').'" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 52 52"><circle class="checkmark__circle" cx="26" cy="26" r="25" fill="none"/><path class="checkmark__check" fill="none" d="M14.1 27.2l7.1 7.2 16.7-16.8"/></svg>'
    ),
    
    $pre.'file_customer_info__notes' => array(
      '#type' => 'textarea',
      '#attributes' => array('placeholder' => 'Notes'),
      '#resizable' => FALSE,
      '#rows' => 2,
      '#default_value' => variable_get($pre.'file_customer_info__notes', 0),
      '#prefix' => '<div class="col-md-8">',
      '#suffix' => '</div>'
    ),

    $pre.'file_customer_info__completed' => array(
      '#type' => 'hidden',
      '#default_value' => variable_get($pre.'file_customer_info__completed', date('U'))
    ),
    
    $pre.'file_customer_info__updated' => array(
      '#type' => 'hidden',
      '#default_value' => variable_get($pre.'file_customer_info__updated', date('U'))
    ),
    
    'description' => array(
      '#markup' => '<div class="col-md-12"><small class="help">The customer info sheet has been completed in Asana.</small></div>'
    )
  );
  
  $form = system_settings_form($form);
  
  $form['actions']['submit']['#value'] = 'Save Progress';

  return $form;
}
