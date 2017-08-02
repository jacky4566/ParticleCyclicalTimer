/*
  The MIT License (MIT)

  Copyright (c) 2017 jacky4566

  Permission is hereby granted, free of charge, to any person obtaining a copy of
  this software and associated documentation files (the "Software"), to deal in
  the Software without restriction, including without limitation the rights to
  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
  the Software, and to permit persons to whom the Software is furnished to do so,
  subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

//Asymmetric cyclic timer
//Used to set ON - OFF style RTC timer

#include "application.h" //needed for all Particle libraries

#ifndef Photon_Cyclic_Timer_h
#define Photon_Cyclic_Timer_h

class cycleTimer{
 public:
	//Create instance of libary 
    cycleTimer(byte ONhour, byte ONmin, byte OFFhour, byte OFFmin);
	
	//Returns true if this timer is active
	boolean isActive();
	
	//Set on time for this timer
	void setOnTime (byte hour, byte min);
	
	//Set off time for this timer
	void setOffTime (byte hour, byte min);

 protected:
	byte _ONhour;
	byte _ONmin;
	byte _OFFhour;
	byte _OFFmin;
};

#endif
