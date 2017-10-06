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
?>
<div class="container-fluid">
<div id="arctic_seo_content_overview">
  <?php print _arctic_render_views_block('arctic_seo', 'arctic_seo_content_overview'); ?>
</div>
</div>