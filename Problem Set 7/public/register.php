<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["username"] == NULL || $_POST["password"] == NULL)
        {
            apologize("You must enter a username or password");
        }
        
        else if ($_POST["password"] != $_POST["confirmation"])
        {
            apologize("Your password and confirmation do not match");
        }
        else 
        {
            $result = CS50::query("SELECT * FROM users WHERE username = ?", $_POST["username"]);
            if (count($result) == 1)
            {
                apologize("Username is already exists");
                echo "<a href='https://ide50-magistrzp.cs50.io/register.php'>go back</a>";
            }
        }
        
        if (count($result) == 0)
        {
            CS50::query("INSERT INTO users (username, hash, cash) VALUES(?, ?, 10000.00)", $_POST["username"], crypt($_POST["password"]));
        }
        $rows = CS50::query("SELECT LAST_INSERT_ID() AS id");
        $id = $rows[0]["id"];
        session_start();
        $_SESSION["id"] = $id;
       
       
           header('Location: https://ide50-magistrzp.cs50.io/login.php'); 
           exit;
       
       
    }
   
?>