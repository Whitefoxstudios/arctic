<?php
$prt_token = variable_get('arctic_prt_token', '10227-XKYNU7E2MIOI');
$prt_site = urlencode(variable_get('arctic_prt_site', $GLOBALS['base_url']));
$prt_url = "https://proranktracker.com/ext/?t=$prt_token&s=$prt_site";
?>

<div class="container-fluid">
  <h2>Rank Report:</h2>
  
  <iframe id="prt" src="<?php print $prt_url; ?>"></iframe>
</div>
