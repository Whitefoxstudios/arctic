(function($){
  'use-strict';

  $(document).ready(function(e){
    $('.arctic_menu--convert_builder').responsiveIframe({xdomain:'*'});
    $('.cb--pane').responsiveIframe({xdomain:'*'});

    $('.arctic-menu-icon a, a.arctic-menu-toggle').each(function(i, o){
      $(o).click(function(e){
        e.preventDefault();

        e.stopImmediatePropagation();

        $('body').toggleClass('arctic-menu-open');
      });
    });
  });
  
  $(window).on('resize', function(e){
    $('.arctic_menu--convert_builder').responsiveIframe({xdomain:'*'});
    $('.cb--pane').responsiveIframe({xdomain:'*'});
  });
  
  $('.arctic_menu--convert_builder-preview-pane').on('update', function(e){
    $('.arctic_menu--convert_builder').responsiveIframe({xdomain:'*'});
    $('.cb--pane').responsiveIframe({xdomain:'*'});
  });  
})(this.jQuery);
