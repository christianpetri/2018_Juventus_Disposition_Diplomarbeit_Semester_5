// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
	Name:       Self_Contained_Collection_Calendar.ino
	Created:	10.10.2018 18:00:06
	Author:     LAPTOP-GNDS6P63\-
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//
void digitalClockDisplay();
void printDigits(int digits);


// Define Functions below here or use other .ino or cpp files
//


#include <TimeLib.h>
#include <Time.h>
int colletionDate[][3] = {
		{ 1536537600,2,10 },
		{ 1536537600,2,7 },
		{ 1536537600,2,11 },
		{ 1536624000,2,8 },
		{ 1536710400,2,5 },
		{ 1536710400,2,6 },
		{ 1537142400,5,8 },
		{ 1537228800,4,4 },
		{ 1537228800,4,5 },
		{ 1537228800,4,1 },
		{ 1537228800,4,6 },
		{ 1537315200,4,10 },
		{ 1537315200,4,7 },
		{ 1537315200,4,11 },
		{ 1537315200,4,8 },
		{ 1537315200,4,9 },
		{ 1537315200,5,7 },
		{ 1537747200,2,1 },
		{ 1537833600,2,4 },
		{ 1537920000,2,5 },
		{ 1537920000,2,9 },
		{ 1538352000,5,2 },
		{ 1538438400,5,10 },
		{ 1538438400,5,11 },
		{ 1538438400,5,3 },
		{ 1538438400,5,9 },
		{ 1538524800,5,4 },
		{ 1538784000,5,5 },
		{ 1538784000,5,6 },
		{ 1538956800,2,10 },
		{ 1538956800,2,7 },
		{ 1538956800,2,11 },
		{ 1539043200,2,8 },
		{ 1539129600,2,5 },
		{ 1539129600,2,6 },
		{ 1539561600,5,8 },
		{ 1539734400,5,7 },
		{ 1540166400,2,1 },
		{ 1540252800,2,4 },
		{ 1540339200,2,5 },
		{ 1540339200,2,9 },
		{ 1540771200,5,2 },
		{ 1540857600,5,10 },
		{ 1540857600,5,11 },
		{ 1540857600,5,3 },
		{ 1540857600,5,9 },
		{ 1540944000,5,4 },
		{ 1541203200,5,5 },
		{ 1541203200,5,6 },
		{ 1541376000,2,10 },
		{ 1541376000,2,7 },
		{ 1541376000,2,11 },
		{ 1541462400,2,8 },
		{ 1541548800,2,5 },
		{ 1541548800,2,6 },
		{ 1541980800,5,8 },
		{ 1542153600,5,7 },
		{ 1542585600,2,1 },
		{ 1542672000,2,4 },
		{ 1542758400,2,5 },
		{ 1542758400,2,9 },
		{ 1543190400,5,2 },
		{ 1543276800,5,10 },
		{ 1543276800,5,11 },
		{ 1543276800,5,3 },
		{ 1543276800,5,9 },
		{ 1543363200,5,4 },
		{ 1543622400,5,5 },
		{ 1543622400,5,6 },
		{ 1543795200,2,10 },
		{ 1543795200,2,7 },
		{ 1543795200,2,11 },
		{ 1543881600,2,8 },
		{ 1543968000,2,5 },
		{ 1543968000,2,6 },
		{ 1544400000,5,8 },
		{ 1544572800,5,7 },
		{ 1545004800,2,1 },
		{ 1545091200,2,4 },
		{ 1545177600,2,5 },
		{ 1545177600,2,9 },
		{ 1545609600,5,2 },
		{ 1545868800,5,10 },
		{ 1545868800,5,11 },
		{ 1545868800,5,3 },
		{ 1545868800,5,9 },
		{ 1545955200,5,4 },
		{ 1546214400,2,10 },
		{ 1546214400,2,7 },
		{ 1546214400,2,11 }
};
String typeName[] = { "Grüngut", "Karton", "Kehricht und Sperrgut", "Metall", "Papier" };
String circleName[] = { "1", "1a", "1b", "2", "3", "4", "5", "6", "7", "8", "9" };

// The setup() function runs once each time the micro-controller starts
void setup()
{
	Serial.begin(9600);
	Serial.println("");
	Serial.println("");

}

// Add the main program code into the continuous loop() function
void loop()
{
	setTime(1536537600 + 7 * 60 * 60);
	digitalClockDisplay();
	Serial.println(now()); 
	showCalendar(); 
	showCurrentEvents();  
	showCurrentEventForCircleId(10); 
	delay(100000);

}

void digitalClockDisplay() {
	// digital clock display of the time
	Serial.print(hour());
	printDigits(minute());
	printDigits(second());
	Serial.print(" ");
	Serial.print(day());
	Serial.print(" ");
	Serial.print(month());
	Serial.print(" ");
	Serial.print(year());
	Serial.println();
}

void printDigits(int digits) {
	// utility function for digital clock display: prints preceding colon and leading 0
	Serial.print(":");
	if (digits < 10)
		Serial.print('0');
	Serial.print(digits);
}

void showCalendar() {
	for (int i = 0; i < sizeof(colletionDate) / sizeof(colletionDate[0]); i++) {
		Serial.printf("\nindex %d\n date: %d", i, colletionDate[i][0]);
		Serial.print(" type: ");
		Serial.print(typeName[colletionDate[i][1] - 1]);
		Serial.print(" circle: ");
		Serial.print(circleName[colletionDate[i][2] - 1]);
	}
}

void showCurrentEvents() {
	Serial.println("------");
	Serial.println("showCurrentEvents");
	
 
	for (int i = 0; i < sizeof(colletionDate) / sizeof(colletionDate[0]); i++) {
		if (colletionDate[i][0] + 7 * 60 * 60 >= now() && colletionDate[i][0] - 6 * 60 * 60 <= now()) {
			Serial.printf("\nindex %d date: %d\t", i, colletionDate[i][0]);
			Serial.print(" type: ");
			Serial.print(typeName[colletionDate[i][1] - 1]);
			Serial.print(" circle: ");
			Serial.print(circleName[colletionDate[i][2] - 1]);
		}
	}
	Serial.println("------");
}

void showCurrentEventForCircleId(int cirleID) {
	Serial.println("");
	Serial.print("showCurrentEventForCircleId ");
	Serial.print(cirleID);
	for (int i = 0; i < sizeof(colletionDate) / sizeof(colletionDate[0]); i++) {
		if (colletionDate[i][2] == cirleID) {
			if (colletionDate[i][0] + 7 * 60 * 60 >= now() && colletionDate[i][0] - 6 * 60 * 60 <= now()) { 
				Serial.printf("\nindex %d date: %d\t", i, colletionDate[i][0]);
				Serial.print(" type: ");
				Serial.print(typeName[colletionDate[i][1] - 1]);
				Serial.print(" circle: ");
				Serial.print(circleName[colletionDate[i][2] - 1]);
			}
		} 
	}
}

