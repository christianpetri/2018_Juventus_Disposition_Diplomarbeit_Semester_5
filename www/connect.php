<?php
class HandelDB
{
    private $ini = array();

    private function connectToDB()
    {
        $this->ini = parse_ini_file('../.ini');

        //echo print_r($this->ini);
        try {
            //$this->conn = new PDO("mysql:host={$this->ini['servername']};dbname={$this->ini['db']};charset=utf8mb4",$this->ini['username'],$this->ini['password']);
			$this->conn = new PDO("mysql:host=mysql.collectioncalendar.christianpetri.ch;dbname=collectioncalendar_christianpetri_ch;charset=utf8mb4","collectioncalend","DBcu3!!Z8G_Kvu!V");
            // set the PDO error mode to exception
            $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        } catch (PDOException $e) {
                echo "Connection failed: " . $e->getMessage();
        }
        $this->ini = "";
    }

    private function select($sql)
    {
        try {
            $stmt = $this->conn->prepare($sql);
            $stmt->execute();
            return $stmt->fetchAll(PDO::FETCH_ASSOC);
        } catch (PDOException $e) {
            echo $e->getMessage();
        }
    }
    //close the DB connection
    private function disconectFromDB()
    {
        $sql= null;
        $stmt = null;
        $this->conn = null;
    }

    public function getResults($sql)
    {
        $this->connectToDB();
        return $this->select($sql);
        $this->disconectFromDB();
    }

	public function getPlainTextStringForMicroprocessor($garbage_type_id,$circle_id){
		try {
			$this-> connectToDB();
			$stmt =  $this->conn->prepare('
				SELECT COUNT(*) AS result
				FROM collection_calendar
				WHERE
				DATE_ADD( collection_calendar.collection_date, INTERVAL -6 HOUR) < DATE_ADD( now(), INTERVAL 9 HOUR)
				and
					DATE_ADD( collection_calendar.collection_date, INTERVAL 7 HOUR) > DATE_ADD( now(), INTERVAL 9 HOUR)
				and
					garbage_type_id = :garbage_type_id
				and
					circle_id = :circle_id
				');
			$stmt->bindParam(':garbage_type_id',	$garbage_type_id,	PDO::PARAM_INT);
			$stmt->bindParam(':circle_id',			$circle_id,			PDO::PARAM_INT);
			$stmt->execute();
            return $stmt->fetchAll(PDO::FETCH_ASSOC);
        } catch (PDOException $e) {
            echo $e->getMessage();
        }
		$this->disconectFromDB();
	}
}

$DB = new HandelDB;
