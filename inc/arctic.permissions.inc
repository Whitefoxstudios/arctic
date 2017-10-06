<?php
function arctic_permission(){
  return array(
    'access arctic overview' => array(
      'title' => t('Access Arctic overview'),
      'description' => t('Grants access to Arctic overview page.'),
    ),

    'access arctic reports rank' => array(
      'title' => t('Access Arctic rank reports'),
      'description' => t('Grants access to Arctic rank reports page.'),
    ),

    'access arctic reports traffic' => array(
      'title' => t('Access Arctic traffic reports '),
      'description' => t('Grants access to Arctic traffic reports page.'),
    ),

    'access arctic reports leads' => array(
      'title' => t('Access Arctic leads reports '),
      'description' => t('Grants access to Arctic leads reports page.'),
    ),

    'access arctic support' => array(
      'title' => t('Access Arctic support'),
      'description' => t('Grants access to Arctic support page.'),
    ),

    'access arctic deliverables' => array(
      'title' => t('Access Arctic deliverables reports'),
      'description' => t('Grants access to Arctic deliverables page.'),
    ),

    'access arctic json' => array(
      'title' => t('Access Arctic json'),
      'description' => t('Grants access to Arctic json output.'),
    ),

    'configure arctic' => array(
      'title' => t('Configure Arctic'),
      'description' => t('Grants access to configure Arctic admin settings.'),
    ),

    'view all asana projects' => array(
      'title' => t('View All Asana Projects'),
      'description' => t('Grants access to view all asana projects.'),
    ),
  );
}
