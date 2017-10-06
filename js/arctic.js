(function($){
  'use-strict';
  
  $(document).ready(function(e){
    $(window).on('resize', function(){
      $('.highcharts-container').each(function(i,o){
        $(o).css({'width':$(o).parents('.container-fluid').width+'px'});
      });
      
      $('[data-destination]').click(function(e){        
        location.href=$(this).attr('data-destination');
      });
    });
    
    $('.arctic-toggle-tab').click(function(e){
      $('.arctic-toggle-tab, .arctic-tab-pane').removeClass('active');
      
      $(this).addClass('active');
      
      $($(this).attr('href')).addClass('active');
      
      $(this).find('.chosen-container').css({width:'100%'});
    });
    
    if(location.hash.length > 0){
      $('[href="'+location.hash+'"]').trigger('click');
    }
    
  });
})(this.jQuery);