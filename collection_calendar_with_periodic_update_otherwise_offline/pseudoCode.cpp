//Libary Stuff

// The setup() function runs once each time the micro-controller starts 
void setup(){
	 
	if (isWiFiCredentialsSet()){
		goToSoftAPmode(); //the user has to enter their credentials
	}
	 connectToWifi()();
}

// here is where you'd put code that needs to be running all the time.
void loop(){
	if (isCalendarStillUpdate()) {
		digitalClockDisplay();
		showCurrentEventForCircleId("User_Set_Circle_ID");
	}
	else {
		getColletionCalendarData();
		getCurrentUnixTime();
		goOffline();
	}
	delay(1000); //wait for a second
}

void connectToWifi(){}

boolean isWiFiCredentialsSet(){}

void goToSoftAPmode(){}

void isCalendarStillUpdate() {}

void digitalClockDisplay(){}

void showCurrentEventForCircleId(int CirleID){}

void getColletionCalendarData(){}

void getCurrentUnixTime() {}

void goOffline(){}
