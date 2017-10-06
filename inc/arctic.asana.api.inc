<?php
require drupal_get_path('module', 'arctic').'/lib/asana/vendor/autoload.php';

use Asana\Client;

$arctic_asana_api_key = variable_get('arctic_asana_api_key', '0/d0ab7d6cb7d5fb1fa5d8c817e8e98a27');

putenv("ASANA_ACCESS_TOKEN=$arctic_asana_api_key");

function _arctic_asana_get_client(){
  $ASANA_ACCESS_TOKEN = getenv('ASANA_ACCESS_TOKEN');

  return Asana\Client::accessToken($ASANA_ACCESS_TOKEN);
}

function _arctic_asana_get_workspaces(){
  $client = _arctic_asana_get_client();

  $workspaces = array();

  $all_workspaces = $client->workspaces->findAll();

  foreach($all_workspaces as $workspace){
    $space = json_decode(json_encode($workspace), true);

    $workspaces[$space["name"]] = $space;
  }

  return $workspaces;
}

function _arctic_asana_get_workspace_idByName($name){
  $workspaces = _arctic_asana_get_workspaces();

  return $workspaces[$name]['id'];
}

function _arctic_asana_get_projects($workspace_id = false){
  $client = _arctic_asana_get_client();

  if(!$workspace_id){
    $workspace_id = _arctic_asana_get_workspace_idByName('Clients');
  }

  $workspace_projects = $client->projects->findByWorkspace($workspace_id);

  $projects = array();

  foreach($workspace_projects as $project){
    $project = json_decode(json_encode($project), true);

    $projects[$project["name"]] = $project;
  }

  asort($projects);

  return $projects;
}

function _arctic_asana_get_projects_options(){
  $result = _arctic_asana_get_projects();

  $projects = array();

  foreach($result as $key => $value){
    $projects[$value['id']] = $key;
  }
  
  asort($projects);

  return $projects;
}

function _arctic_asana_get_projectById($id = false){
  if(!$id){
    $id = variable_get('arctic_asana_project', false);
  }

  $projects = _arctic_asana_get_projects_options();

  $name = $projects[$id];

  $all_projects = _arctic_asana_get_projects();

  return $all_projects[$name];
}

function _arctic_asana_get_project($id = false){
  $pid = ($id) ? $id : variable_get('arctic_asana_project', $id);

  if(!$pid){
    return false;
  }

  $client = _arctic_asana_get_client();

  return $client->projects->findById($pid);
}

function _arctic_asana_get_projects_complete($id = false){
  $projects = _arctic_asana_get_projects();

  $complete = array();

  foreach($projects as $name => $data){
    $complete[$name] = _arctic_asana_get_project($data['id']);
  }

  return $complete;
}

function _arctic_asana_get_project_sections($project = false){
  if(!$project){
    $project = _arctic_asana_get_project();
  }

  $id = $project->id;

  $client = _arctic_asana_get_client();

  $all_sections = $client->projects->sections($id);

  $sections = array();

  foreach($all_sections as $section){
    $sections[$section->name] = $section;
  }

  return $sections;
}

function _arctic_asana_get_project_tasks($project = false){
  if(!$project){
    $project = _arctic_asana_get_project();
  }

  $id = $project->id;

  $client = _arctic_asana_get_client();

  $all_tasks = $client->tasks->findByProject($id);

  $tasks = array();

  foreach($all_tasks as $task){
    $task_info = $client->tasks->findById($task->id);

    $tasks[$task->name] = $task_info;
  }

  return $tasks;
}

function _arctic_asana_get_project_deliverables($project = false){
  $tasks = _arctic_asana_get_project_tasks($project);

  usort($tasks, function($a, $b){
    return strcmp($a->modified_at, $b->modified_at);
  });

  rsort($tasks);

  $deliverables = array();

  foreach($tasks as $key => $task){
    if(is_object($task->memberships[0]->section)
    && isset($task->memberships[0]->section->name)
    && preg_match('/deliverables|20\d\d\s?:/i', $task->memberships[0]->section->name)
    && (!preg_match('/((deliverables|20\d\d)\s?:|template)/i', $task->name))){
      $deliverables[$task->name] = $task;
    }
  }

  return $deliverables;
}

function _arctic_asana_obj_to_arr($arr){
  return json_decode(json_encode($arr), true);
}
