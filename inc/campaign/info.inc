<?php
function arctic_campaign_info_form(){
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
    '#prefix' => '<div class="col-md-6">',
    '#suffix' => '</div>',
  );

  $pre = 'arctic_campaign_info__';

  $form['settings'][$pre.'filing_agent'] = array(
    '#type' => 'select',
    '#title' => 'Filing Agent',
    '#empty_option' => ' - Choose Agent - ',
    '#options' => array(
      'benji' => 'Benji',
      'byron' => 'Byron',
      'michael' => 'Michael',
      'jd' => 'JD'
    ),
    '#default_value' => variable_get($pre.'filing_agent', NULL),
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

  $form['settings']['dates']['output'] = array(
    '#markup' => "<p>Filed: $filed_date <br>\n Updated: $updated_date</p>"
  );

  $form['main']['#type'] = 'container';
  $form['main']['#attributes']['class'][] = 'row';

  $left = &$form['main']['left'];
  $left['#type'] = 'container';
  $left['#attributes']['class'][] = 'col-md-4';

  $mid = &$form['main']['mid'];
  $mid['#type'] = 'container';
  $mid['#attributes']['class'][] = 'col-md-4';

  $right = &$form['main']['right'];
  $right['#type'] = 'container';
  $right['#attributes']['class'][] = 'col-md-4';

  $primary_location = &$left['primary_location'];
  $primary_location['#type'] = 'fieldset';
  $primary_location['#title'] = 'Primary Location';
  $primary_location['#tree'] = FALSE;

  $primary_location[$pre.'primary_location__name'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Company Name'),
    '#default_value' => variable_get($pre.'primary_location__name', FALSE),
  );

  $primary_location['address'] = array(
    '#type' => 'fieldset',
    '#title' => 'Address',
    '#tree' => FALSE,

    $pre.'primary_location__street' => array(
      '#type' => 'textfield',
      '#attributes' => array('placeholder' => 'Street'),
      '#default_value' => variable_get($pre.'primary_location__street', FALSE)
    ),

    $pre.'primary_location__city' => array(
      '#type' => 'textfield',
      '#attributes' => array('placeholder' => 'City'),
      '#default_value' => variable_get($pre.'primary_location__city', FALSE)
    ),

    $pre.'primary_location__state' => array(
      '#type' => 'textfield',
      '#attributes' => array('placeholder' => 'State'),
      '#default_value' => variable_get($pre.'primary_location__state', FALSE)
    ),

    $pre.'primary_location__zip' => array(
      '#type' => 'textfield',
      '#attributes' => array('placeholder' => 'Zip'),
      '#default_value' => variable_get($pre.'primary_location__zip', FALSE)
    )
  );

  $primary_location[$pre.'primary_location__phone'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Phone'),
    '#default_value' => variable_get($pre.'primary_location__phone', FALSE),
  );

  $primary_location[$pre.'primary_location__email'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Email'),
    '#default_value' => variable_get($pre.'primary_location__email', FALSE),
  );

  $mid['goals'] = array(
    '#type' => 'fieldset',
    '#title' => 'Campaign Goals',
    '#tree' => FALSE
  );

  $mid['goals'][$pre.'keywords'] = array(
    '#type' => 'textarea',
    '#attributes' => array('placeholder' => 'Keywords - one per line'),
    '#default_value' => variable_get($pre.'keywords', FALSE),
    '#value_callback' => array('_'.$pre.'keywords__value'),
    '#rows' => 5
  );

  $mid['goals'][$pre.'areas'] = array(
    '#type' => 'textarea',
    '#attributes' => array('placeholder' => 'Service Areas - one per line'),
    '#default_value' => variable_get($pre.'areas', FALSE),
    '#rows' => 2
  );

  $mid['goals'][$pre.'categories'] = array(
    '#type' => 'textarea',
    '#attributes' => array('placeholder' => 'Categories - one per line'),
    '#default_value' => variable_get($pre.'categories', FALSE),
    '#value_callback' => array('_'.$pre.'keywords__value'),
    '#rows' => 2
  );

  $hours = &$right['hours'];
  $hours['#type'] = 'fieldset';
  $hours['#title'] = 'Hours';
  $hours['#tree'] = FALSE;

  $days = array(
    'Mo' => 'Monday',
    'Tu' => 'Tuesday',
    'We' => 'Wednesday',
    'Th' => 'Thursday',
    'Fr' => 'Friday',
    'Sa' => 'Saturday',
    'Su' => 'Sunday'
  );

  $hour_options = array();

  for($i = 0; $i<24; $i++){
    $h = ($i > 12) ? $i - 12 : $i;

    $m = ($i < 12) ? 'am' : 'pm';

    $hour_options["$i:00"] = "$h:00$m";
    $hour_options["$i:30"] = "$h:30$m";
  }

  foreach($days as $key => $value){
    $short = strtolower($key);
    $var_prefix = $pre.'hours_'.$short;

    $hours[$short] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('form-inline')),

      $var_prefix.'__status' => array(
        '#type' => 'checkbox',
        '#title' => $value,
        '#default_value' => variable_get($var_prefix.'__status', 1)
      ),

      $var_prefix.'__open' => array(
        '#type' => 'select',
        '#title' => 'Open',
        '#options' => $hour_options,
        '#attributes' => array('class' => array('chosen')),
        '#empty_value' => '9:00',
        '#empty_option' => '9:00am',
        '#default_value' => variable_get($var_prefix.'__open', NULL)
      ),

      $var_prefix.'__close' => array(
        '#type' => 'select',
        '#title' => 'Close',
        '#options' => $hour_options,
        '#attributes' => array('class' => array('chosen')),
        '#empty_value' => '17:00',
        '#empty_option' => '5:00pm',
        '#default_value' => variable_get($var_prefix.'__close', NULL)
      ),
    );

    if($key == 'Sa' || $key == 'Su'){
      $hours[$short][$var_prefix.'__status']['#default_value'] = variable_get($var_prefix.'__status', 0);
    }
  }

  $primary_contact = &$right['primary_contact'];
  $primary_contact['#type'] = 'fieldset';
  $primary_contact['#title'] = 'Primary Contact';
  $primary_contact['#tree'] = FALSE;

  $primary_contact[$pre.'primary_contact__name'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Client Name'),
    '#default_value' => variable_get($pre.'primary_contact__name', FALSE),
  );

  $primary_contact[$pre.'primary_contact__phone'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Phone'),
    '#default_value' => variable_get($pre.'primary_contact__phone', FALSE),
  );

  $primary_contact[$pre.'primary_contact__email'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Email'),
    '#default_value' => variable_get($pre.'primary_contact__email', FALSE),
  );

  $social = &$mid['social'];

  $social['#type'] = 'fieldset';
  $social['#title'] = 'Social Media Links';
  $social['#tree'] = FALSE;

  $social[$pre.'social_facebook'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Facebook'),
    '#default_value' => variable_get($pre.'social_facebook', FALSE),
  );

  $social[$pre.'social_twitter'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Twitter'),
    '#default_value' => variable_get($pre.'social_twitter', FALSE),
  );

  $social[$pre.'social_googleplus'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Google+'),
    '#default_value' => variable_get($pre.'social_googleplus', FALSE),
  );

  $social[$pre.'social_linkedin'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'LinkedIn'),
    '#default_value' => variable_get($pre.'social_linkedin', FALSE),
  );

  $social[$pre.'social_pinterest'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Pinterest'),
    '#default_value' => variable_get($pre.'social_pinterest', FALSE),
  );

  $social[$pre.'social_youtube'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'YouTube'),
    '#default_value' => variable_get($pre.'social_youtube', FALSE),
  );

  $social[$pre.'social_instagram'] = array(
    '#type' => 'textfield',
    '#attributes' => array('placeholder' => 'Instagram'),
    '#default_value' => variable_get($pre.'social_instagram', FALSE),
  );

  $form = arctic_checklist_form($form);

  $form['actions']['submit']['#value'] = 'Update Info';

  return $form;
}

function _arctic_campaign_info__keywords__value($element, $input = FALSE, &$form_state){
  if($input){
    return preg_replace('/,\s?/', "\r\n", $element['#value']);
  }
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
