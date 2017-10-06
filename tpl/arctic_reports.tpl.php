<?php
function _arctic_render_views_block($view, $block){
  $block = block_load('views', "$view-$block");
  $block->title="";
  $block->region="none";
  $blocks = array($block);
  $block_render = _block_render_blocks($blocks);
  $rendered_arr = _block_get_renderable_array($block_render);
  
  $output = drupal_render($rendered_arr);        
  return $output;
}

$arctic_reports_block_info = array(
  'arctic_rank_total' => array(
    'view' => 'arctic_rank',
    'block' => 'arctic_rank_total',
  ),
  'arctic_traffic_pageviews_total' => array(
    'view' => 'arctic_traffic',
    'block' => 'arctic_traffic_pageviews_total',
  ),
  'arctic_leads_total' => array(
    'view' => 'arctic_leads',
    'block' => 'arctic_leads_total',
  ),
  'arctic_seo_total' => array(
    'view' => 'arctic_seo',
    'block' => 'arctic_seo_total',
  ),
  'arctic_traffic_pageviews' => array(
    'view' => 'arctic_traffic',
    'block' => 'arctic_traffic_pageviews',
  ),
  'arctic_traffic_metrics' => array(
    'view' => 'arctic_traffic',
    'block' => 'arctic_traffic_metrics',
  ),
  'arctic_traffic_top_pages' => array(
    'view' => 'arctic_traffic',
    'block' => 'arctic_traffic_top_pages',
  ),
  'arctic_traffic_top_referrers' => array(
    'view' => 'arctic_traffic',
    'block' => 'arctic_traffic_top_referrers',
  ),
);

$arctic_reports_blocks = array();

foreach($arctic_reports_block_info as $key => $value){
  $arctic_reports_blocks[$key] = _arctic_render_views_block($value['view'], $value['block']);
}

extract($arctic_reports_blocks);

$arctic_overview_blocks = array_filter(array(
  'arctic_rank_total color-block bg-red-200' => $arctic_rank_total,
  'arctic_traffic_pageviews_total color-block bg-amber-200' => $arctic_traffic_pageviews_total,
  'arctic_leads_total color-block bg-light_green-200' => $arctic_leads_total,
  'arctic_seo_total color-block bg-deep_purple-200' => $arctic_seo_total,
));

$aoblocks = array_filter(array(
  'arctic_rank_total' => array(
    'block' => $arctic_rank_total,
    'color' => 'red-200',
    'icon' => 'trending_up',
    'destination' => 'reports/rank',
  ),
  'arctic_traffic_pageviews_total' => array(
    'block' => $arctic_traffic_pageviews_total,
    'color' => 'amber-200',
    'icon' => 'call_merge',
    'destination' => 'reports/traffic',
  ),
  'arctic_traffic_leads_total' => array(
    'block' => $arctic_leads_total,
    'color' => 'light_green-200',
    'icon' => 'ring_volume',
    'destination' => 'reports/leads',
  ),
  'arctic_seo_total' => array(
    'block' => $arctic_seo_total,
    'color' => 'deep_purple-200',
    'icon' => 'check_circle',
    'destination' => 'reports/seo',
  ),
));

foreach($aoblocks as $key => $info){
  if(!$info['block']){
    unset($aoblocks[$key]);
  }
}

$aoblocks_columns = 'col-md-'.round(12/count($aoblocks));
$aoblocks_rendered = '';

foreach($aoblocks as $key => $info){
  extract($info);
  
  $aoblocks_rendered.= '<div class="'.$aoblocks_columns.'"><div data-destination="/admin/arctic/'.$destination.'" class="'.$key.' color-block bg-'.$color.'"><i class="material-icons pull-right">'.$icon.'</i>'.$block.'</div></div>';
}
?>

<section id="arctic-reports-overview">
  <div class="container-fluid">
    <div class="row arctic-overview-blocks clearfix">
      <div id="rank"></div>
      <?php print $aoblocks_rendered; ?>
    </div>
  </div>
</section>

<section id="arctic-traffic-pageviews">
  <div class="container-fluid">
    <div class="row arctic-traffic-pageviews clearfix">
      <div class="col-md-12">
        <div class="elevate-block"><?php print $arctic_traffic_pageviews; ?></div>
      </div>
    </div>
  </div>
</section>

<section class="section-padding" id="arctic-traffic-metrics">
  <div class="container-fluid">
    <div class="row arctic-traffic-metrics clearfix">
      <div class="col-md-12">
        <div class="elevate-block"><?php print $arctic_traffic_metrics; ?></div>
      </div>
    </div>
  </div>
</section>

<section class="section-padding" id="arctic-traffic-top-pages-referrers">
  <div class="container-fluid">
    <div class="row arctic-traffic-top-pages-referrers clearfix">
      <div class="col-md-12">
        <div class="elevate-block"><?php print $arctic_traffic_top_pages; ?></div>
      </div>
  
      <div class="col-md-12">
        <div class="elevate-block"><?php print $arctic_traffic_top_referrers; ?></div>
      </div>
    </div>
  </div>
</section>