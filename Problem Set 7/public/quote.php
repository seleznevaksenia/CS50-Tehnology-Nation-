<?php

require("../includes/config.php"); 
    // if form was submitted
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // lookup stock info
        $stock = lookup($_POST["symbol"]);
        if ($stock === false)
        {
            apologize("Invalid stock symbol");
        }
        
        // else render quote_price
        render("quote_price.php", ["title" => "Quote", "symbol" => $stock["symbol"], "name" => $stock["name"], "price" => $stock["price"]]);
    }
    else
    {
        // else render quote_form
        render("quote_form.php", ["title" => "Quote"]);
    }

?>