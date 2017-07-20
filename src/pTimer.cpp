/*
    Copyright 2016-2017 Balazs Toth
    This file is part of ProLog.

    ProLog is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ProLog is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with ProLog.  If not, see <http://www.gnu.org/licenses/>.

    For more information please visit: https://bitbucket.org/nauticleproject/
*/

#include "pTimer.h"

using namespace ProLog;

/////////////////////////////////////////////////////////////////////////////////////////
/// Constructor that initializes start and end timers to 0.
/////////////////////////////////////////////////////////////////////////////////////////
pTimer::pTimer() {
	time(&start);  // seconds from the reference date (1900.01.01)
	estimated_finish = start;
}
/////////////////////////////////////////////////////////////////////////////////////////
/// Sets the timer (start) to the current time.
/////////////////////////////////////////////////////////////////////////////////////////
void pTimer::tic() {
	start_tick = std::chrono::system_clock::now();
	ticked = true;
}
/////////////////////////////////////////////////////////////////////////////////////////
/// Sets the timer (end) to the current time.
/////////////////////////////////////////////////////////////////////////////////////////
void pTimer::tac() {
	end_tick = std::chrono::system_clock::now();
	ticked = false;
}
/////////////////////////////////////////////////////////////////////////////////////////
/// Returns the difference between start and end in seconds
/////////////////////////////////////////////////////////////////////////////////////////
std::chrono::duration<double> pTimer::get_difference() const {
	return (end_tick-start_tick);
}
/////////////////////////////////////////////////////////////////////////////////////////
/// Returns the date of the object creation.
/////////////////////////////////////////////////////////////////////////////////////////
struct tm pTimer::get_start() const {
	return *localtime(&start);
}
/////////////////////////////////////////////////////////////////////////////////////////
/// Returns the date of call.
/////////////////////////////////////////////////////////////////////////////////////////
struct tm pTimer::get_current() const {
	time_t current;
	time(&current);
	return *localtime(&current);
}
/////////////////////////////////////////////////////////////////////////////////////////
/// Returns the estimated end date based on the object creation and the progress.
/////////////////////////////////////////////////////////////////////////////////////////
struct tm pTimer::get_estimated_finish(float const& progress) {
	if(progress<1e-2f) {
		return *localtime(&start);
	}
	time_t current_time;
	time(&current_time);
	estimated_finish = (current_time-start)/progress*100.0f+start;
	return *localtime(&estimated_finish);
}
