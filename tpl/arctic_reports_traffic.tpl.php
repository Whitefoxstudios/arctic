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
  $arctic_reports_blocks[$key] = '<div class="elevate-block">'._arctic_render_views_block($value['view'], $value['block']).'</div>';
}

extract($arctic_reports_blocks);

?>

<h1 class="container-fluid page-header">Traffic Report <small>(Last 30 Days)</small></h1>

<section class="section-padding" id="arctic-traffic-pageviews">
  <div class="container-fluid">
    <div class="row arctic-traffic-pageviews clearfix">
      <div class="col-md-12">
        <?php print $arctic_traffic_pageviews; ?>
      </div>
    </div>
  </div>
</section>

<section class="section-padding" id="arctic-traffic-metrics">
  <div class="container-fluid">
    <div class="row arctic-traffic-metrics clearfix">
      <div class="col-md-12">
        <?php print $arctic_traffic_metrics; ?>
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
        <?php print $arctic_traffic_top_referrers; ?>
      </div>
    </div>
  </div>
</section>
