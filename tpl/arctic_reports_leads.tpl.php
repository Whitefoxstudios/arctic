<?php
function _arctic_render_views_block($view, $block){
  $block = block_load('views', "$view-$block");
  $block->title="";
  $block->region="none";
  $output = drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));        
  return $output;
}
?>
<div class="container-fluid">
 <?php print _arctic_render_views_block('arctic_leads', 'arctic_leads_submissions') ?>
</div>