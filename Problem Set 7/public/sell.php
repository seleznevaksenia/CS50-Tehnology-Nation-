<?php

    // configuration
    require("../includes/config.php");

    $result = CS50::query("SELECT symbol FROM clients WHERE id_user = ?", $_SESSION["id"]);
    if (count($result) == 0)
        {
        apologize("First you must buy something!");
        }
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
               
        $transaction = 'SELL';

        $stock = lookup($_POST["symbol"]);
        
        $shares = CS50::query("SELECT shares FROM clients WHERE id_user = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        $value = $stock["price"] * $shares[0]["shares"];
        
        // add the sale value to cash
        CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $value, $_SESSION["id"]);
        // delete the stock from their portfolio 
        CS50::query("DELETE FROM clients WHERE id_user = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);        
        
        // update history
        CS50::query("INSERT INTO history (id_user, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $_POST["symbol"], $shares[0]["shares"], $stock["price"]);
        
        redirect("/");
    }
    
    else
    {
         $symbol = CS50::query("SELECT symbol FROM clients WHERE id_user = ?", $_SESSION["id"]);
         render("sell_form.php", ["title" => "Sell", "symbol" => $symbol]);
    }

    
    
    
?>