<?php
$arctic = drupal_get_path('module', 'arctic');

include_once "$arctic/inc/arctic.checklist.core.inc";

function arctic_campaign_launch_form(){
  $pre = 'arctic_campaign_launch__';

  $form = _arctic_checklist_form_settings(_arctic_checklist_form_assets($form), $pre, 'Launching');

  $items[] = array(
    'name' => 'set_analytics_id',
    'title' => 'Set Analytics ID',
    'help' => 'The Google Analytics ID has been set.',
    'fields' => array(
      'googleanalytics_account' => array(
        '#type' => 'textfield',
        '#title' => 'Analytics Property ID',
        '#default_value' => variable_get('googleanalytics_account', FALSE),
      ),

      'arctic_ga_user' => array(
        '#type' => 'textfield',
        '#title' => 'Analytics User Account',
        '#default_value' => variable_get('arctic_ga_user', FALSE),
        '#autocomplete_path' => 'admin/arctic/campaign/launch/analytics-accounts.json',
      ),
    ),
  );

  $items[] = array(
    'name' => 'configured_recaptcha',
    'title' => 'Configured ReCaptcha',
    'help' => 'The ReCaptcha API Key and Secret have been set.',
    'fields' => array(
      'recaptcha_site_key' => array(
        '#type' => 'textfield',
        '#title' => 'Site Key',
        '#default_value' => variable_get('recaptcha_site_key', FALSE),
      ),

      'recaptcha_secret_key' => array(
        '#type' => 'textfield',
        '#title' => 'Secret Key',
        '#default_value' => variable_get('recaptcha_secret_key', FALSE),
      ),
    ),
  );

  $home = url("/", array('absolute' => TRUE));

  $base_url = (!$GLOBALS['base_url'] == 'default') ? $GLOBALS['base_url'] : $home;

  $xmlsitemap_base_url = variable_get('xmlsitemap_base_url', $base_url);

  $items[] = array(
    'name' => 'set_sitemap_base_url',
    'title' => 'Set Sitemap Base Url',
    'help' => 'The Sitemap Base Url has been set.',
    'fields' => array(
      'xmlsitemap_base_url' => array(
        '#type' => 'textfield',
        '#title' => 'Default base URL',
        '#default_value' => $xmlsitemap_base_url,
      ),
    ),
  );

  $items[] = array(
    'name' => 'updated_sitemap',
    'title' => 'Updated Sitemap',
    'help' => 'The Sitemap has been updated',
    'fields' => array(
      'link' => array(
        '#markup' => '<div class="form-item"><label>Update Sitemap</label><a href="/admin/config/search/xmlsitemap" class="btn btn-primary btn-block mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--convert" target="_blank">Update<i class="material-icons right">cached</i></a></div>'
      ),
    ),
  );

  $items[] = array(
    'name' => 'sitemap_verified',
    'title' => 'Sitemap Verified',
    'help' => 'The Sitemap has been verified',
    'fields' => array(
      'link' => array(
        '#markup' => '<div class="form-item"><label>Verify Sitemap</label><a href="'.url('/sitemap.xml', array('absolute' => TRUE)).'" class="btn btn-success btn-block mdl-button mdl-js-button mdl-button--raised mdl-js-ripple-effect mdl-button--success" target="_blank">Verify<i class="material-icons right">external link</i></a></div>'
      ),
    ),
  );

  $items[] = array(
    'name' => 'domain_transferred',
    'title' => 'Domain Transferred',
    'help' => 'The Domain has been transferred and/or domain credentials stored in asana',
  );

  $items[] = array(
    'name' => 'kw_research',
    'title' => 'Keywords Researched',
    'help' => 'ahrefs keyword research has been performed and top keyword targets have been discussed with the client and stored in asana and Pro Rank Tracker',
    'fields' => array(
      'arctic_campaign_info__keywords' => array(
        '#type' => 'textarea',
        '#attributes' => array('placeholder' => '5 Keywords'),
        '#default_value' => variable_get('arctic_campaign_info__keywords', FALSE),
      )
    )
  );

  $items[] = array(
    'name' => 'metatag',
    'title' => 'Metatag Module Configured ',
    'help' => 'Metatags module is properly configured see: https://bobdavischimney.com',
  );

  $items[] = array(
    'name' => 'titles_descriptions',
    'title' => 'Unique Titles & Descriptions',
    'help' => 'All pages have optimized page titles and descriptions',
  );

  $items[] = array(
    'name' => 'oriinal_urls',
    'title' => 'Optimized URLS',
    'help' => 'All pages have optimized urls or urls have been carried over from the previous website',
  );

  $items[] = array(
    'name' => 'redirects',
    'title' => '301 Redirects Configured',
    'help' => 'All not found errors have been fixed with 301 Redirects',
  );

  $items[] = array(
    'name' => 'original_copy',
    'title' => 'ProRankTracker Setup',
    'help' => 'The ProRankTracker profile has been setup and all target keywords are stored there',
  );

  $items[] = array(
    'name' => 'contact_info_verified',
    'title' => 'Contact Info Verified',
    'help' => 'Company name, address, phone and primary email have been filed and verified with the customer',
  );

  $items[] = array(
    'name' => 'webform_emails_set',
    'title' => 'Webform Emails Set',
    'help' => 'ALL webform emails have been set and ALL webform tests have been received by the client',
  );

  $items[] = array(
    'name' => 'converions_goals',
    'title' => 'Conversion Goals',
    'help' => 'ALL conversion goals have been setup in Analytics and confirmed to be working',
  );

  $items[] = array(
    'name' => 'webform_every_page',
    'title' => 'Webform on EVERY page',
    'help' => 'Or obvious point of content where not applicable',
  );

  $items[] = array(
    'name' => 'responsinator',
    'title' => 'Responsinator Test',
    'help' => 'All pages are confirmed to be responsive',
  );

  $items[] = array(
    'name' => 'responsinator',
    'title' => 'Responsinator Test',
    'help' => 'All pages are confirmed to be responsive',
  );

  $items[] = array(
    'name' => 'admin_password',
    'title' => 'Admin Password Set',
    'help' => 'The admin user password has been updated with the White Fox password formula',
  );

  $items[] = array(
    'name' => 'apache_config',
    'title' => 'Apache2 Config Created',
    'help' => 'The server configuration has been correctly setup',
  );

  $items[] = array(
    'name' => 'ssl_encryption',
    'title' => 'SSL Encryption Setup',
    'help' => 'An SSL certificate has been generated and installed for the domain. (SEO Clients Only)',
  );

  $items[] = array(
    'name' => 'ssl_errors',
    'title' => 'SSL Errors',
    'help' => 'All SSL "mixed content" warnings have been found and fixed',
  );

  $items[] = array(
    'name' => 'search_console',
    'title' => 'Google Search Console',
    'help' => 'Properties have been added for all variations of the domain and the preferred url has been set',
  );

  $items[] = array(
    'name' => 'backup_migrate',
    'title' => 'Website Backed Up',
    'help' => 'Backup & Migrate has been properly configured and website has been backed up',
  );

  $items[] = array(
    'name' => 'search_console',
    'title' => 'Google Search Console',
    'help' => 'Properties have been added for all variations of the domain and the preferred url has been set',
  );

  $items[] = array(
    'name' => 'img_optimization',
    'title' => 'Images Optimized',
    'help' => 'All images are downsized to smallest possible dimensions, compressed and have alt/title properties and every page has at least one image',
  );

  $items[] = array(
    'name' => 'proofread',
    'title' => 'Proofreading',
    'help' => 'All pages, headings, titles and content has been read through and contain no grammatical or spelling errors',
  );

  $items[] = array(
    'name' => 'internal_links',
    'title' => 'Internal Link Building',
    'help' => 'All pages, contain relevant links to other pages on the website within their content',
  );

  $items[] = array(
    'name' => 'mobile_usability',
    'title' => 'Mobile Usability Tested',
    'help' => 'All pages, have been tested to maximize mobile usability',
  );

  $items[] = array(
    'name' => 'gmb',
    'title' => 'Google My Business Verified',
    'help' => 'Google My Business listing has been created or claimed and verified or postcard has been sent out',
    'fields' => array(
      'arctic_gmb_account_email' => array(
        '#type' => 'textfield',
        '#attributes' => array(
          'placeholder' => array('Account')
        ),
        '#default_value' => variable_get('arctic_gmb_account_email', FALSE),
        '#autocomplete_path' => 'admin/arctic/campaign/launch/analytics-accounts.json',
      )
    )
  );

  $items[] = array(
    'name' => 'campaign_outline',
    'title' => 'Marketing Campaign Outline',
    'help' => 'Marketing campaign goals have been discussed and campaign outline has been created',
    'fields' => array(
      'arctic_marketing_campaign_outline' => array(
        '#type' => 'text_format',
        '#help' => 'legitimate campaign outline or a link to one',
        '#default_value' => variable_get('arctic_marketing_campaign_outline', FALSE),
        '#after_build' => array('arctic_hide_format_tips_field'),
      ),
    ),
  );

  $items[] = array(
    'name' => 'uptime_reporting_enabled',
    'title' => 'Uptime Reporting Enabled',
    'help' => 'Company name and domain have been added to StatusCake for uptime monitoring',
  );

  $items[] = array(
    'name' => 'seo_backup',
    'title' => '2nd Backup and Migrate',
    'help' => 'The website has been backed up again',
  );

  $form += _arctic_build_checklist($items, $pre);

  return arctic_checklist_form($form);
}

function arctic_hide_format_tips_field(&$form){
  $form['format']['#type'] = 'hidden';
  $form['format']['#attributes']['class'][] = 'element-invisible';
  $form['format']['format']['#value'] = 'full_html';

  return $form;
}