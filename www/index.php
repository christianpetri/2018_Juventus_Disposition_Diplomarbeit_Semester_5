<?php
 	 date_default_timezone_set('Europe/London');
    include("connect.php");
?> 
<html lang="en">
   <head>
      <title>Collection Calendar</title> 
       <style type="text/css">
           html{
               background-color:black;
           }
           body{
               padding: 20px;
               max-width: 1000px;
               margin:auto;
               background-color: white;
           }
            
            table.result {
                border-collapse: collapse;
            }

            table.result th {
                border: 1px solid black;
                padding: 5px;
            }
           table.result td{
                border: 1px solid black;
                padding: 5px;
            }
       
       </style> 
   </head>
<body> 
      <h1>Collection Calendar</h1> 
	  <h2>Next Dates</h2>

<?php 
    $result = $DB->getResults(" 
		SELECT collection_date, garbage_type_description,circle_description FROM `collection_calendar` 
		LEFT JOIN circle on circle.circle_id = collection_calendar.circle_id 
		LEFT JOIN garbage_type ON garbage_type.garbage_type_id = collection_calendar.garbage_type_id
		WHERE collection_calendar.collection_date >= CURDATE()
		LIMIT 30
	");
	 
   //echo print_r($result);
    $html="";
    $html = '<table class="result">';
    // header row
    $html .= '<tr>'; 
            $html .='<th> Date </th> <th> Type </th> <th> Circle </th>'; 
    $html .='</tr>';

    // data rows
foreach ($result as $key => $value) {	
    $html .= '<tr>';
    $html .= '<td>' . htmlspecialchars($result[$key]['collection_date']). '</td>';
    $html .= '<td>' . htmlspecialchars($result[$key]['garbage_type_description']). '</td>';
    $html .= '<td>' . htmlspecialchars($result[$key]['circle_description']). '</td>';
    $html .= '</tr>';
}

    // finish table and return it

    $html .= '</table>';
    echo $html; 
 
?>
</body>
</html>
