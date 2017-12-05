<!DOCTYPE html>
  <html lang="en">

  <head>
    <title></title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="css/style.css" rel="stylesheet">
  </head>

  <body>
    <form action="index.php">
      School name
      <br>
      <input type="text" name="name">
      <br> School category
      <br>
      <input type="text" name="category">
      <br> Student count
      <br>
      <input type="number" name="students">
      <br><br>
      <input type="submit" value="Submit">
    </form>
  </body>

  <?php

  $file = 'file.json';

  if (file_exists($file)) {
    $filedata = file_get_contents($file);

    $objson = json_decode($filedata, true);

    if (!empty($_GET)) {
      writeJson($objson, $file);

      $filedata = file_get_contents($file);
      $objson = json_decode($filedata, true);
    }

    echo "<hr /><code><pre>";
    print_r($objson);
    echo "</pre></code><hr />";
  }
  else echo $file . ' doesnt exist';

  function writeJson($objson, $fileOutput){
    $name = $_GET["name"];

    $objson["school"][$name]["category"] = $_GET["category"];
    $objson["school"][$name]["nr_students"] = $_GET["students"];
    /*$objson["school"][$name]["courses"]["AV"] = "Audio Video";
    $objson["school"][$name]["courses"]["AT"] = "AutoTech";*/

    $saveJson = json_encode($objson);
    $file = fopen($fileOutput, "w") or die ("can't open file"); 

    fwrite($file, $saveJson);
    fclose($file);
  }


  ?>

  </html>