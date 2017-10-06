<?php

function _arctic_build_checklist($items, $pre){
  $form = array();

  foreach($items as $item){
    $form += _arctic_build_checklist_item($item, $pre);
  }

  return $form;
}

function _arctic_build_checklist_item($item, $pre){
  extract($item);

  $form[$name] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('row checklist-item')),
    '#tree' => TRUE,

    $pre.$name.'__status' => array(
      '#type' => 'checkbox',
      '#title' => $title,
      '#default_value' => variable_get($pre.$name.'__status', 0),
      '#prefix' => '<div class="col-md-4 fancy">',
      '#suffix' => '<div class="description"><small class="help">'.$help.'</small></div></div>',
      '#field_suffix' => '<svg class="checkmark'.((variable_get($pre.$name.'__status', 0) == 1) ? ' checked' : '').'" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 52 52"><circle class="checkmark__circle" cx="26" cy="26" r="25" fill="none"/><path class="checkmark__check" fill="none" d="M14.1 27.2l7.1 7.2 16.7-16.8"/></svg>'
    ),

    'fields' => array(
      '#type' => 'container',
      '#attributes' => array('class' => array('col-md-8')),
    ),

    $pre.$name.'__completed' => array(
      '#type' => 'hidden',
      '#default_value' => variable_get($pre.$name.'__completed', date('U'))
    ),

    $pre.$name.'__updated' => array(
      '#type' => 'hidden',
      '#default_value' => variable_get($pre.$name.'__updated', date('U'))
    ),
  );

  $fields[$pre.$name.'__notes'] = array(
    '#type' => 'textarea',
    '#attributes' => array('placeholder' => 'Notes'),
    '#resizable' => FALSE,
    '#rows' => 2,
    '#default_value' => variable_get($pre.$name.'__notes', FALSE),
  );

  $cols = round(12/count($fields));

  foreach($fields as &$field){
    $field['#prefix'] = '<div class="col-md-'.$cols.'">';

    $field['#suffix'] = '</div>';
  }

  $form[$name]['fields'] += $fields;

  return $form;
}

function _arctic_checklist_form_assets($form = array()){
  $arctic = drupal_get_path('module', 'arctic');

  $form['#attached']['css']['//cdnjs.cloudflare.com/ajax/libs/chosen/1.5.1/chosen.min.css']['type'] = 'external';
  $form['#attached']['css']["$arctic/css/checklist.css"]['type'] = 'file';

  $form['#attached']['js']['//cdnjs.cloudflare.com/ajax/libs/chosen/1.5.1/chosen.jquery.min.js']['type'] = 'external';
  $form['#attached']['js']["$arctic/js/checklist.js"]['type'] = 'file';

  return $form;
}

function _arctic_checklist_form_settings($form = array(), $pre = 'arctic_', $agent_type = false){
  $agent_type = ($agent_type) ? $agent_type : 'Working';

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
    '#prefix' => '<div class="col-md-6">',
    '#suffix' => '</div>',
  );

  $form['settings'][$pre.strtolower($agent_type).'_agent'] = array(
    '#type' => 'select',
    '#title' => "$agent_type Agent",
    '#empty_option' => ' - Choose Agent - ',
    '#options' => array(
      'benji' => 'Benji',
      'byron' => 'Byron',
      'michael' => 'Michael',
      'jd' => 'JD'
    ),
    '#default_value' => variable_get($pre.strtolower($agent_type).'_agent', NULL),
    '#required' => TRUE,
    '#attributes' => array('class' => array('chosen')),
    '#prefix' => '<div class="col-md-3">',
    '#suffix' => '</div>',
  );

  $form['settings']['dates']['#type'] = 'container';
  $form['settings']['dates']['#attributes']['class'][] = 'col-md-3';

  $form[$pre.'filed'] = array(
    '#type' => 'hidden',
    '#value' => variable_get($pre.'filed', date('U')),
  );

  $form[$pre.'updated'] = array(
    '#type' => 'hidden',
    '#value' => variable_get($pre.'updated', date('U')),
  );

  $filed_date = date('m/d/Y h:i:sa', variable_get($pre.'filed', date('U')));
  $updated_date = date('m/d/Y h:i:sa', variable_get($pre.'updated', date('U')));

  $filed = (!date('m/d/Y h:i:sa', date('U')) == $filed_date) ? "Filed: $filed_date <br>\n" : "";
  $updated = (!date('m/d/Y h:i:sa', date('U')) == $updated_date) ? "Updated: $updated_date" : "";

  $form['settings']['dates']['output']['#markup'] = "<p>$filed $updated</p>";

  return $form;
}

function arctic_checklist_form($form) {
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save Progress'));

  if (!empty($_POST) && form_get_errors()) {
    drupal_set_message(t('The settings have not been saved because of the errors.'), 'error');
  }

  $form['#submit'][] = 'arctic_checklist_form_submit';

  if (!isset($form['#theme'])) {
    $form['#theme'] = 'system_settings_form';
  }

  return $form;
}

function arctic_checklist_form_submit($form_id, &$form_state){
  $values = &$form_state['values'];

  arctic_walk_form_values($values);

  drupal_set_message('Your progress were saved!');
}

function arctic_walk_form_values($values){
  foreach($values as $key => $value){
    if(is_array($value)){
      arctic_walk_form_values($value);
    } else {
      variable_set($key, $value);
    }
  }
}

function _arctic_csv_to_array($file){
  $csv = array_map('str_getcsv', file($file));

  array_walk($csv, function(&$a) use ($csv) {
    $a = array_combine($csv[0], $a);
  });

  array_shift($csv);

  return $csv;
}