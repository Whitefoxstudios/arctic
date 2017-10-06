(function($){
  'use-strict';

  $(document).ready(function(e){
    $('.form-text, .form-textarea').each(function(i,o){
      if($(o).attr('id').length && $(o).attr('id').match(/(title|description)/i)){
        var total = $(o).attr('id').match(/title/i) ? 65 : 160,

        count = $(o).val().length,

        percent = ($(o).val().length/total)*100,

        danger = '#ffc107',
        warn = count > total ? '#f44336' : danger,
        success = count < total-4 ? '#4caf50' : warn,

        $arcticCount = $('<div/>',{
          class: 'arctic-count',
          html: '<div class="arctic-count--value">'+count+'</div>',
        }).css({
          position: 'relative',
          width: $(o).outerWidth()+'px'
        }),

        $arcticCountBar = $('<div/>', {
          class: 'arctic-count--bar',
        }).css({
          position: 'absolute',
          top: 0, left: 0,
          background: success,
          width: percent + '%',
          height: '2px',
        });

        $arcticCount.appendTo($(o).parents('.form-item'));

        $arcticCount.append($arcticCountBar);

        $(o).on('keyup keypress keydown click focus blur input', function(e){
          var c = $(o).val().length, p = (c/total)*100;

          $arcticCount.find('>.arctic-count--value').text(c);

          $arcticCountBar.css({
            width: p+'%',
            background: c < total-4 ? '#4caf50' : c > total ? '#f44336' : '#ffc107',
          });
        });
      }
    });
  });
})(this.jQuery);
