<!DOCTYPE html>
<html>
  <head>
    <title></title>
  </head>
  <body>
    <?php
    switch (2) {
        case 0:
            echo 'The value is 0';
            break;
        case 1:
            echo 'The value is 1';
            break;
        case 2:
            echo 'The value is 2';
            break;
        default:
            echo "The value isn't 0, 1 or 2";
    }
  
  // alternative
  //switch(2):
  //  case 0: echo "the value is 0"; break;
  //  case 1: echo "the value is 1"; break;
  //  case 2: echo "the value is 2"; break;
  //  default: echo "none of the above";
  //endswitch;
    ?>
    </body>
</html>
