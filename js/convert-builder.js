var ri = responsiveIframe();

ri.allowResponsiveEmbedding();

(function($){
  'use-strict';

  $(document).ready(function(e){
    var parentDoc = $(window.parent.document),
        preview = parentDoc.find('.arctic_menu--convert_builder-preview-pane'),
        here = window.location.href;
    
    $('.form-radio').each(function(i, o){
      var o = $(o), v = o.val(), there = here+'/'+v;

      o.on('click', function(e){
        var pane = $('<iframe/>', {
          class: 'cb--pane '+v,
          src: there
        });
        
        preview.html(pane);
        
        preview.trigger('update', v);
      });
    });
        
    preview.on('update', function(e, data){
      console.log(e, data);
      
      parentDoc.find('.arctic_menu--convert_builder').responsiveIframe({xdomain:'*'});
      parentDoc.find('.cb--pane').responsiveIframe({xdomain:'*'});
    });    
  });
})(this.jQuery);
