<?php
function arctic_vars_flush($variable = null){
  if(is_null($variable) || $variable == 'all'){
    foreach(arctic_vars_get() as $var){
      variable_del($var);

      drupal_set_message(t('deleted variable: @var', array('@var' => $var)));
    }
  } else {
    variable_del($variable);

    drupal_set_message(t('deleted variable: @var', array('@var' => $variable)));
  }
}

function arctic_vars_get(){
  return db_select('variable', 'v')
  ->fields('v', array('name'))
  ->condition('name', db_like('arctic_') . '%', 'LIKE')
  ->execute()
  ->fetchCol();
}
