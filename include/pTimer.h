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

#ifndef _TIMER_H_
#define _TIMER_H_

#include <time.h>
#include <chrono>


namespace ProLog {
	/** This class manages the timer. Measures time between calls of tic() and tac().
	// 	It can also estimate the finish date of the simulation.
	*/
	class pTimer final {
		time_t start;
		time_t estimated_finish;
		std::chrono::time_point<std::chrono::system_clock> start_tick;
		std::chrono::time_point<std::chrono::system_clock> end_tick;
		bool ticked=false;
	public:
		pTimer();
		~pTimer()=default;
		void tic();
		void tac();
		std::chrono::duration<double> get_difference() const;
		struct tm get_start() const;
		struct tm get_estimated_finish(float const& progress);
		struct tm get_current() const;
	};
}

#endif //_TIMER_H_