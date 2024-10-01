<!DOCTYPE html>
<html>
    <head>
    <title>A loop of your own</title>
        <link type='text/css' rel='stylesheet' href='style.css'/>
  </head>
  <body>
    <?php
    //Add while loop below
    $notHeads=true;
    // can also have while(cond){ }
    while($notHeads):
        $flip = rand(0,1);
        ++$flipCount;
        if($flip)
        {
            $notHeads=false;
            echo "<p>Got heads!";
            echo "<div class=\"coin\">Head</div></p>";//coin
        }
        else
        {
            echo "<p>Tails again";
            echo "<div class=\"coin\">Tail</div></p>";//coin
        }
    endwhile;
    
    // do while
    //do{
    //  ...
    //  ...
    //} while(cond);
    
    $verb = "were";
    $last = "flips";
    if ($flipCount == 1) {
      $verb = "was";
      $last = "flip";
    }
    echo "<p>There {$verb} {$flipCount} {$last}!</p>";
    ?>
    </body>
</html>

// style.css
.coin {
    height: 50px;
    width: 50px;
    border-radius: 25px;
    background-color: gray;
  text-align: center;
  font-weight: bold;
  font-family: sans-serif;
  color: white;
  margin: 10px;
  display: inline-block;
  line-height: 50px;
  font-size: 16px;
}
