(function($){
  $(document).ready(function() {
    $('.loader').addClass('loading');
    
    var  personal_access_token = Drupal.settings.arctic.asana_api_key,
                        client = Asana.Client.create().useAccessToken(personal_access_token),
                    project_id = Drupal.settings.arctic.asana_project_id;


    client.tasks.findByProject(project_id).then(function(collection){
      collection.fetch(200).then(function(allTasks){
        $(allTasks).each(function(i,o){
          client.tasks.findById(o.id).then(function(task){
            var section = task.memberships[0].section.name;
            var isDeliverable = /(deliverables|20\d\d)\s?:/ig;
            var notTemplate = /((deliverables|20\d\d)\s?:|template)/ig;

            if(isDeliverable.test(section) && (!notTemplate.test(task.name))){
              $('<div/>', {
                class: 'elevate-block deliverable',
                id: task.id,
                html: '<div class="inner"><h2>'+task.name+'</h2><div class="content">'+task.notes+'</div></div>'
              }).appendTo('#deliverables');
              
              $('.loader').removeClass('loading');
            }
          });
        });
      });
    });

  });
})(jQuery)
