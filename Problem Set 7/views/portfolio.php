<div>
  <table class="table table-striped" style="text-align:left">
<?php
			print("<tr>");
				print("<th>Symbol</th>");
				print("<th>Name</th>");
				print("<th>Shares</th>");
				print("<th>Price</th>");
				print("<th>Total value</th>");
			print("</tr>");
				  
			foreach ($positions as $position)
			{	  
				print("<tr>");
				print("<td>" . $position["symbol"] . "</td>");
				print("<td>" . $position["name"] . "</td>");
				print("<td>" . $position["shares"] . "</td>");
				print("<td>" . $position["price"] . "</td>");
				print("<td>" . $position["total"]=$position["shares"]*$position["price"]. "</td>");
				print("</tr>");
			}
		?>
		<tr>
        <td colspan="4">CASH</td>
        <?php
        foreach ($cash as $totals)
        {
            	print("<td>" . number_format($totals["cash"], 2) . "</td>");
        }
        ?>
        </tr>
</table>
</div>
