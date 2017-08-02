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

#include "ParticleCyclicalTimer.h"

 //Initialize
 cycleTimer::cycleTimer(byte ONhour, byte ONmin, byte OFFhour, byte OFFmin){
	 _ONhour = ONhour;
	 _ONmin  = ONmin;
	 _OFFhour = OFFhour;
	 _OFFmin  = OFFmin;
 }
 
 //Return true if timer is active
 boolean cycleTimer::isActive(){
	//Functions Time.Hour and Time.minute use Local time!
	int _timeLocal = (Time.hour() * 3600) + (Time.minute() * 60);
	//convert ON and OFF times to seconds from midnight
	int _onFromMidnight  = ((int)_ONhour * 3600) + ((int)_ONmin * 60);
	int _offFromMidnight = ((int)_OFFhour * 3600) + ((int)_OFFmin * 60);
	
	if(_onFromMidnight < _offFromMidnight)//Normal Routine
		if(_timeLocal > _onFromMidnight && _timeLocal < _offFromMidnight){ //Time is between alarms
			return true;
		}
		else
			return false;
	else if(_onFromMidnight > _offFromMidnight)//Inverted Routine
		if(_timeLocal >= _onFromMidnight || _timeLocal <= _offFromMidnight){ //Time is outside alarms
			return true;
		}
		else
			return false;
}
 
//Set on time for this timer
void  cycleTimer::setOnTime (byte hour, byte min){
	_ONhour = hour;
	_ONmin  = min;
}
	
//Set off time for this timer
void  cycleTimer::setOffTime (byte hour, byte min){
	_OFFhour = hour;
	_OFFmin  = min;
}

//Get time remaining in this timer. Returns 0 if off.
int  cycleTimer::getRemainingTime (){
	int _timeLocal = (Time.hour() * 3600) + (Time.minute() * 60) + Time.second();
	int _offFromMidnight = ((int)_OFFhour * 3600) + ((int)_OFFmin * 60);
	int _delta = _offFromMidnight - _timeLocal;
	if (_delta <= 0){
		return 0;
	}
	else {
		return _delta;
	}
}
	
