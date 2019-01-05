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
      <p><a href='/doc'>Doc: How to use for your own project</a></p>
	  <h2>Next 30 Dates</h2>

<?php
    $result = $DB->getCalendarEntries();

   //echo print_r($result);
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
        $html .= '<td><span title="circle_id '.htmlspecialchars($result[$key]['circle_id']).'">'. htmlspecialchars($result[$key]['circle_description']). '</span></td>';
        $html .= '</tr>';
    }
    // finish table and return it
    $html .= '</table>';
    echo $html;
?>
</body>
</html>
