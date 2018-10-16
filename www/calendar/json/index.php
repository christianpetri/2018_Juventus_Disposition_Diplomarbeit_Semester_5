<?php
include("../../connect.php");
header('Content-Type: application/json');
echo $DB->getEntireCalendarInJSON();
