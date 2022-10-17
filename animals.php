<!DOCTYPE html>
<html>
    <head>
        <title>Animal</title>

        <style>
            .content {
                display: flex;
                flex-direction: row;
                justify-content: center;
                padding: 10px;
                align-items: center;
            }

            #description {
                padding: 40px;
                align-items: center;
            }

        </style>
    </head>
    <body>
        <?php
        if ($_POST['animal'] === "wolf")
        {
            $animal = "Wolf"; 
            $image = "./theZoo/image_wolf.jpeg";
            $description = "./theZoo/descript_wolf.txt";
        }
        else if ($_POST['animal'] === "orca")
        {
            $animal = "Orca"; 
            $image = "./theZoo/image_orca.jpg";
            $description = "./theZoo/descript_orca.txt";
        }
        else if ($_POST['animal'] === "sqrl")
        {
            $animal = "Squirrel"; 
            $image = "./theZoo/image_sqrl.jpg";
            $description = "./theZoo/descript_sqrl.txt";
        }
        else if ($_POST['animal'] === "elph")
        {
            $animal = "Elephant"; 
            $image = "./theZoo/image_elph.jpg";
            $description = "./theZoo/descript_elph.txt";
        }
        else if ($_POST['animal'] === "grff")
        {
            $animal = "Giraffe"; 
            $image = "./theZoo/image_grff.jpg";
            $description = "./theZoo/descript_grff.txt";
        }
        else if ($_POST['animal'] === "lion")
        {
            $animal = "Lion"; 
            $image = "./theZoo/image_lion.jpg";
            $description = "./theZoo/descript_lion.txt";
        }
        ?>

        <div class="content">
            <div id="image">
                <?php 
                    echo "<img src='$image' alt='$animal' width=400 height=400><br>";
                ?>
            </div>
    
            <div id="description">
                <h1> You choose <?php echo $animal ?> </h1>
                <?php 
                    $myfile = fopen($description, "r") or die("Unable to open file!");
                    echo fread($myfile,filesize($description));
                    fclose($myfile);
                ?>
            </div>
        </div>
    </body>
</html>