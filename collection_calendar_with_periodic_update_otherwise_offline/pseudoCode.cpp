//Libary Stuff
int colletionDate[][3] = { }; //{Date in Unix, garbageTypeId, circleId}
String typeName[] =
{ "Grüngut", "Karton", "Kehricht und Sperrgut", "Metall", "Papier" };
String circleName[] = { "1", "1a", "1b", "2", "3", "4", "5", "6", "7", "8", "9", };

// The setup() function runs once each time the micro-controller starts 
void setup(){
	if (isWiFiCredentialsSet()){
		goToSoftAPmode(); //the user has to enter their credentials
	}
	 connectToWifi();
}

// Add the main program code into the continuous loop() function
void loop()
{
	if (isCalendarStillUpdate()) {
		digitalClockDisplay();
		showCurrentEventForCircleId(«User_Set_Cirle_ID»);
		delay(1000); //Wait for a second
	}
	else {
		goOnline()
		getColletionCalendarData();
		getCurrentUnixTime();
		goOffline();
	} 
}
 
void connectToWifi(){ ... }
boolean isWiFiCredentialsSet(){ ... }
void goToSoftAPmode(){ ... }
void isCalendarStillUpdate() { ... }
void digitalClockDisplay() { ... }
void showCurrentEventForCircleId(int cirleID) { ... }
void goOnline() { ... }
void getColletionCalendarData() { ... }
void getCurrentUnixTime() { ... }
void goOffline() { ... }

