<?php
include("../connect.php");
header("Content-Type: text/plain");
date_default_timezone_set('Europe/London');
//include("logic.php");
$circle_id = $_GET["circle_id"];
$html="1";

for ($garbage_type_id = 1; $garbage_type_id <= 5; $garbage_type_id++) {
	$result = $DB->getPlainTextStringForMicroprocessor( $garbage_type_id , $circle_id );
	//echo print_r($result);
	foreach ($result as $key => $value){
    $html .=  htmlspecialchars($result[$key]['result']);
  }

}

echo $html;
