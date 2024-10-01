<html>
  <head>
    <title>Leap Years</title>
  </head>
  <body>
    <?php
      for ($leap = 2004; $leap < 2050; $leap = $leap + 4) {
        echo "<p>$leap</p>";
      }
    
      // for each loop
      $langs = array("JavaScript",
            "HTML/CSS", "PHP",
            "Python", "Ruby");
      
      foreach ($langs as $lang) {
          echo "<li>$lang</li>";
      }
      unset($lang);
    ?>
  </body>
</html>
