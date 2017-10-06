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

include_once drupal_get_path('module', 'arctic').'/inc/campaign/citations.inc';
?>

<div class="container-fluid">
  <div id="arctic_campaign_citations">
    <?php print drupal_render(drupal_get_form('arctic_campaign_citations_form')); ?>
  </div>
</div>
