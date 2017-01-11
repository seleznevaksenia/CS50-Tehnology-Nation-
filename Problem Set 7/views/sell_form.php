<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="symbol">
             <option value=""></option>
                <?php
                    foreach($symbol as $item)
                    {
                        echo("<option value='{$item["symbol"]}'>{$item["symbol"]}</option>");
                          
                    }
                ?>
                 </select>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
</form>