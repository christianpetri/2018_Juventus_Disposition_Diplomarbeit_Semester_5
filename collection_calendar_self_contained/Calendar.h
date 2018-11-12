// Calendar.h

#ifndef _CALENDAR_h
#define _CALENDAR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class CalendarClass
{
 protected:


 public:
	void init();
};

extern CalendarClass Calendar;

#endif

