<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]) || empty($_POST["shares"]))
        {
            apologize("You must enter a symbol and quantity of shares to buy.");
        }
        
        // if symbol is invalid
        if (lookup($_POST["symbol"]) === false)
        {
            apologize("Invalid symbol.");
        }
        
        // if non-positive integer
        if (preg_match("/^\d+$/", $_POST["shares"]) == false)
        {
            apologize("You must enter a whole, positive integer.");
        }
        $transaction = 'BUY';
   
        $stock = lookup($_POST["symbol"]);
   
        $cost = $stock["price"] * $_POST["shares"];

        $cash =	CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);	
        $cash = $cash[0]["cash"];
        // if user's cash < total cost 
        if ($cash < $cost)
        {
            apologize("Need more gold, go mine!");
        }         
        // else if user's cash >= total price
        else
        {
            // capitalize symbol
            $_POST["symbol"] = strtoupper($_POST["symbol"]);
                         
            // add stock to their portfolio or update shares
            CS50::query("INSERT INTO clients (id_user, symbol, shares) VALUES(?, ?, ?) 
                ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $_POST["symbol"], $_POST["shares"]);
            
            // subtract total price from their cash
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $cost, $_SESSION["id"]);
             
             //history
            CS50::query("INSERT INTO history (id_user, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $_POST["symbol"], $_POST["shares"], $stock["price"]); 
             
            redirect("/");   
        }
    }
    else
    {
        render("buy_form.php", ["title" => "Buy"]);
    }
?>