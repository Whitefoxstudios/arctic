/*(function($){
  $(document).ready(function(){
    $.ajaxSetup({
      cache: true
    });

    $.ajax({
      url: '/admin/arctic/asana/deliverables.json',
      dataType: 'json',
      method: 'GET',
      beforeSend: function(xhr){
       $('.loader').addClass('loading');
      }
    }).done(function(data){
      var items=[];
      
      $.each(data, function(key, val){
        items.push('<div class="elevate-block deliverable"><div class="inner"><h2>'+key+'</h2><div class="content">'+val.notes+'</div></div></div>');
      });
      
      $('<div/>',{
        class: 'deliverables-list',
        html: items.join(''),
      }).appendTo('#deliverables');
      
      $('.loader').removeClass('loading');
    });
  });
})(jQuery)
*/