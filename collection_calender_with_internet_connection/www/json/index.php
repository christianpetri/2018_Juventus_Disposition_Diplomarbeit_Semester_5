<?php
include("../connect.php");
header('Content-Type: application/json');

$circle_id = $_GET["circle_id"];
echo $DB->getJSON($circle_id);
