<?php

    // configuration
    require("../includes/config.php");

    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if ($_POST["password"] == NULL || $_POST["new_password"] == NULL || $_POST["confirmation"] == NULL)
        {
            apologize("You must enter a username or password");
        }
        if ($_POST["new_password"] != $_POST["confirmation"])
        {
            apologize("Your password and confirmation do not match");
        }
        $rows = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        if (!password_verify($_POST["password"], $rows[0]["hash"]))
            {
               apologize("wrong old password");
            }
        else
        {
            CS50::query("UPDATE users SET hash = ? WHERE id = ?", crypt($_POST["new_password"]), $_SESSION["id"]);
            redirect("/");  
        }
    }
   else
   {
       render("change_form.php", ["title" => "Buy"]);
   }
?>


  
    