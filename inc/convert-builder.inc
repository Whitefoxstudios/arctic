<?php

function arctic_convert_builder_create_form(){
  $key = date('U');

  $back = '<div class="convert_builder--back-wrapper pull-left"><a data-slide="prev" class="convert_builder--back-btn mdl-button mdl-js-button mdl-js-ripple-effect mdl-button--colored" href="#convert_builder-carousel"><span class="fa fa-arrow-left">&nbsp;</span> back</a></div>';

  $next = '<div class="convert_builder--next-wrapper text-right"><a data-slide="next" class="convert_builder--next-btn mdl-button mdl-js-button mdl-js-ripple-effect mdl-button--raised mdl-button--colored" href="#convert_builder-carousel">next <span class="fa fa-arrow-right">&nbsp;</span></a></div>';

  $form['convert_builder'] = array(
    '#type' => 'fieldset',
  );

  $form['convert_builder']['carousel_start'] = array(
    '#markup' => '<div id="convert_builder-carousel" class="carousel slide" data-interval="false"><div class="carousel-inner">',
  );

  $form['convert_builder']['display'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="item convert_builder-carousel-slide-0 active"><div class="item-wrapper"><div class="page-header"><h1>Display Options</h1></div><div class="page-content">',
    '#suffix' => '</div></div></div>',
  );

  $form['convert_builder']['display']["arctic_convert_type_$key"] = array(
    '#type' => 'radios',
    '#title' => 'Choose a conversion design type:',
    '#options' => drupal_map_assoc(explode(',', 'bar,mat,takeover,slider,dialog,sidebar')),
    '#default_value' => variable_get("arctic_convert_type_$key", false),
    '#attributes' => array('class' => array('convert_builder--display-type')),
  );

  $form['convert_builder']['trigger'] = array(
    '#type' => 'fieldset',
    '#prefix' => '<div class="item convert_builder-carousel-slide-1"><div class="item-wrapper"><div class="page-header"><h1>Trigger Options '.$back.'</h1></div><div class="page-content">',
    '#suffix' => '</div></div></div>',
  );

  $form['convert_builder']['trigger']["arctic_convert_trigger_$key"] = array(
    '#type' => 'radios',
    '#title' => 'Choose how to trigger it',
    '#options' => drupal_map_assoc(explode(',', 'immediately,2 second delay,5 second delay,10 second delay,bounce,scroll a little,scroll halfway,scroll to bottom')),
    '#default_value' => variable_get("arctic_convert_trigger_$key", false),
    '#attributes' => array('class' => array('convert_builder--trigger-type')),
  );

  $form['convert_builder']['carousel_end'] = array(
    '#markup' => '</div>'.$next.'</div>',
  );

  $form['#attached'] = array(
    'js' => array(
      '//cdnjs.cloudflare.com/ajax/libs/chosen/1.5.1/chosen.jquery.min.js' => array(
        'type' => 'external',
      ),
      '(function($){
        \'use-strict\';
        
        $(document).ready(function(e){
          $(\'.chosen\').chosen({no_results_text: \'Oops, nothing found!\'});
        });
      })(this.jQuery);' => array(
        'type' => 'inline',
      ),
    ),
    
    'css' => array(
      '//cdnjs.cloudflare.com/ajax/libs/chosen/1.5.1/chosen.min.css' => array(
        'type' => 'external',
      ),
    ),
  );

  return system_settings_form($form);
}
