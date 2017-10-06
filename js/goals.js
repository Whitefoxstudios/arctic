(function($){
  'use-strict';

  $(window).bind('load', function(e){
    $('body :not(script):not(style):not(a):not(iframe):not(object):not(embed)')
    .contents()
    .filter(function(){
      return this.nodeType === 3;
    })
    .replaceWith(function(){
      if(this.nodeValue.match(/\+?1?[\-\s\.]?\(?(\d{3})\)?[\-\s\.]?(\d{3})[\-\s\.]?(\d{4})/g)){
        return this.nodeValue.replace(/\+?1?[\-\s\.]?\(?(\d{3})\)?[\-\s\.]?(\d{3})[\-\s\.]?(\d{4})/g, ` <a href="tel:$1-$2-$3" class="phone-link-processed">$1-$2-$3</a>`);
      } else {
        return this.nodeValue;
      }
    });

    $('a[href^="tel"]:not(.phone-link-processed)').each(function(i, o){
      $(o).attr('href', $(o).attr('href').replace(/\+?1?[\-\s\.]?\(?(\d{3})\)?[\-\s\.]?(\d{3})[\-\s\.]?(\d{4})/g, `$1-$2-$3`));

      $(o).text($(o).text().replace(/\+?1?[\-\s\.]?\(?(\d{3})\)?[\-\s\.]?(\d{3})[\-\s\.]?(\d{4})/g, `$1-$2-$3`));

      $(o).addClass('phone-link-processed');
    });

    $('a[href^="mailto:"]').on('click', function(e){
      var label = 'email '+($(this).attr('href').replace(/mailto:/, ''));

      ga('send', 'event', 'lead', 'click', label);
    });

    $('a[href^="tel:"]').on('click', function(e){
      var label = 'email '+($(this).attr('href').replace(/tel:/, ''));

      ga('send', 'event', 'lead', 'click', label);
    });

    $('input, select, textarea').on('blur focus change autocomplete keyup', function(e){
  	  var label = 'Form: ' +$(this).parents('form').attr('id') +', Field: ' +$(this).attr('id') + ', Value: '+$(this).val();

  	  ga('send', 'event', 'Form Tracking', e, label);
    });

    $('form').on('submit', function(e){
  	  ga('send', 'event', 'lead', 'submission', 'form '+$(this).attr('id'));
    });

    $('a[href*="plus.google.com"], a[href*="www.google.com/+"], a[href*="google.com/maps"], a[href*="goo.gl/maps"]').on('click', function(e){
      var label = 'Google '+$(this).text();

      ga('send', 'event', 'lead', 'click', label);
    });
  });
})(this.jQuery);
