<html>
  <head>
    <title>Woot, Arrays!</title>
  </head>
  <body>
    <?php
      $array = array("Egg", "Tomato", "Beans", "Potatoe");
      echo $array[2];
      //echo array{2}; // alternative syntax
      unset($array[1]); // remove Tomato
      
      foreach($array as $a)
      {
        echo "<p>$a</p>";
      }
      
      // also
      $n = array();
      array_push($n, 1);
      array_push($n, 2);
      array_push($n, 4);
      array_push($n, 8);
      
      print count($n);
      
    ?>
  </body>
</html>
