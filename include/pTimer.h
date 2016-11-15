/////////////////////////////////////////////////////////////////////////////
// Name:        pTimer.h
// Purpose:     pTimer class
// Author:      Balázs Tóth
// Modified by:
// Created:     10/07/2016
// Copyright:   (c) ProLog-project
// Licence:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef _TIMER_H_
#define _TIMER_H_

#include <time.h>
#include <chrono>

/** This class manages the timer. Measures time between calls of tic() and tac().
// 	It can also estimate the finish date of the simulation.
*/
class pTimer final {
	time_t start;
	time_t estimated_finish;
	// clock_t start_tick;
	// clock_t end_tick;
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

#endif //_TIMER_H_