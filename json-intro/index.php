<?php

  $file = 'file.json';

  if (file_exists($file)) {
    $filedata = file_get_contents($file);

    $objson = json_decode($filedata, true);

    echo "<hr /><code><pre>";
    print_r($objson);
    echo "</pre></code><hr />";
  }
  else echo $file . ' doesnt exist';

  /*echo ($objson['school']['mediacollege']['courses']['MD']);
  echo "<br />";
  echo ($objson['school']['pascalzuid']['courses']['VZ']);*/

?>
