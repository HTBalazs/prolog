/////////////////////////////////////////////////////////////////////////////
// Name:        pLogger.h
// Purpose:     pLogger namespace
// Author:      Balázs Tóth
// Modified by:
// Created:     10/07/2016
// Copyright:   (c) ProLog-project
// Licence:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef _LOGGER_H_
#define _LOGGER_H_

#ifndef LOGFILE
#define LOGFILE "sim.log"
#endif //LOGFILE
#ifndef MAX_WARNING
#define MAX_WARNING 10
#endif //MAX_WARNING

#include <iostream>
#include <fstream>
#include <memory>
#include <cstdarg>
#include <stdio.h>
#include <string.h>
#include "pTimer.h"
#include "pFile.h"

/** Global declaration of colors.
*/
extern char NRM[]; 	// normal
extern char RED[];	// red
extern char GRN[];	// green
extern char YEL[];	// yellow
extern char BLU[];	// blue
extern char MAG[];	// magenta
extern char CYN[];	// cyan
extern char LGY[];	// light gray
extern char DGY[];	// dark gray
extern char LRD[];	// light red
extern char LGN[];	// light green
extern char LYW[];	// light yellow
extern char LBL[];	// light blue
extern char LMA[];	// light magenta
extern char LCY[];	// light cyan
extern char WHT[];	// white

#define COLOR WHT
/** This namespace contains functions to place logs to terminal/prompt and file.
*/
namespace pLogger {
	inline bool already_written() {
		static bool written = false;
		return written++;
	}

	inline void to_file(char const* fmt, va_list args) {
		pFile file{LOGFILE, already_written()?"a":"w"};
		file.vfprint(fmt, args);
	}

	template <char const* color> void log(char const* fmt, va_list args) {
	#ifdef __linux__
		printf("%s", color);
	#endif // __linux__
		vprintf(fmt, args);
	#ifdef __linux__
		printf("%s", NRM);
	#endif // __linux__
	}

	template <char const* color> void logf(char const* fmt, ...) {
	    va_list args;		
		va_start(args, fmt);
		log<color>(fmt, args); // 4
		va_end(args);
		va_start(args, fmt);
		to_file(fmt, args);
		va_end(args);
	}

	inline void logf(char const* fmt, ...) {
	    va_list args;
		va_start(args, fmt);
		to_file(fmt, args);
		va_end(args);
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
	}

	template <char const* color> void log(char const* fmt, ...) {
	    va_list args;		
		va_start(args, fmt);
		log<color>(fmt, args); // 4
		va_end(args);
	}

	inline void log(char const* fmt, ...) {
	    va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
	}

	template <char const* color> void footer() {
		log<color>("  ==============================================================================\n");
	}

	template <char const* color> void footerf() {
		logf<color>("  ==============================================================================\n");
	}

	template <char const* color> void finish_prompt() {
		footer<color>();
		log<color>("  Press <Enter> to exit...\n");
	}

	inline void error_msgf(char const* fmt, ...) {
		logf<RED>("  ERROR: ");
		va_list args;
		va_start(args, fmt);
		to_file(fmt,args);
		va_end(args);
		va_start(args, fmt);
		log<RED>(fmt,args);
		va_end(args);
		finish_prompt<RED>();
		std::cin.get();
		exit(1);
	}

	inline void error_msg(char const* fmt, ...) {
		log<RED>("  ERROR: ");
		va_list args;
		va_start(args, fmt);
		log<RED>(fmt,args);
		va_end(args);
		finish_prompt<RED>();
		std::cin.get();
		exit(1);
	}

	inline void warning_msgf(char const* fmt, ...) {
		static int counter = 0;
		counter++;
		if(MAX_WARNING<counter) {
			error_msgf("Maximum allowable warning messages were reached.\n");
		}
		logf<YEL>("  WARNING: ");
		va_list args;
		va_start(args, fmt);
		to_file(fmt,args);
		va_end(args);
		va_start(args, fmt);
		log<YEL>(fmt,args);
		va_end(args);
	}

	inline void warning_msg(char const* fmt, ...) {
		static int counter = 0;
		counter++;
		if(MAX_WARNING<counter) {
			error_msg("Maximum allowable warning messages were reached.\n");
		}
		log<YEL>("  WARNING: ");
		va_list args;
		va_start(args, fmt);
		log<YEL>(fmt,args);
		va_end(args);
	}

	template <char const* color> void header(char const* fmt, ...) {
		footer<color>();
		va_list args;
		va_start(args, fmt);
		log<color>("    ");
		log<color>(fmt, args);
		log<color>("\n");
		va_end(args);
		log<color>("  ------------------------------------------------------------------------------\n");
	}

	template <char const* color> void headerf(char const* fmt, ...) {
		footerf<color>();
		va_list args;
		va_start(args, fmt);
		log<color>("    ");
		log<color>(fmt, args);
		va_end(args);
		va_start(args, fmt);
		logf<color>("    ");
		to_file(fmt,args);
		logf<color>("\n");
		va_end(args);
		logf<color>("  ------------------------------------------------------------------------------\n");
	}

	template <char const* color> void title(char const* fmt, ...) {
		va_list args;
		va_start(args, fmt);
		log<color>("      ");
		log<color>(fmt, args);
		log<color>(":\n");
		va_end(args);
	}

	template <char const* color> void titlef(char const* fmt, ...) {
		va_list args;
		va_start(args, fmt);
		logf<color>("      ");
		logf<color>(fmt, args);
		logf<color>(":\n");
		va_end(args);
	}

	class pLog_stream {
		std::unique_ptr<pTimer> timer;
	public:
		pLog_stream() {
			timer = std::unique_ptr<pTimer>{new pTimer{}};
		}
		inline void print_step_info(int const& steps, float const& dt, int const& substeps, int const& all_steps, float const& current_time, float const& progress) {
			static int counter = 51;

			if(counter==51) {
				footerf<MAG>();
				logf<MAG>("  | ");
				logf<LMA>("N#");
				logf<MAG>(" | ");
				logf<LMA>("Time step");
				logf<MAG>(" | ");
				logf<LMA>("Substeps");
				logf<MAG>(" | ");
				logf<LMA>("All steps");
				logf<MAG>(" |  ");
				logf<LMA>("Time");
				logf<MAG>(" |  ");
				logf<LMA>("ts/s");
				logf<MAG>("  |  ");
				logf<LMA>("Estimated Finish");
				logf<MAG>(" |\n");
				footerf<MAG>();
				counter = 0;
			}
			timer->tac();
			float difference = timer->get_difference();
			float fps = difference==0?0:(float)substeps/difference;
			struct tm est_end = timer->get_estimated_finish(progress);
			logf<WHT>(" %5i   %1.3e      %5i      %6i   %.3f   %06.2f   %02i.%02i.%4i %02i:%02i\n", steps, (double)dt, substeps, all_steps, (double)current_time, (double)fps, est_end.tm_mday, est_end.tm_mon+1, est_end.tm_year+1900, est_end.tm_hour, est_end.tm_min);
			timer->tic();
			counter++;
		}
		inline void print_substep_info(float const& dt, int const& substeps) {
			logf<MAG>(" %5i   %1.3e\n", substeps, dt);
		}
		inline void print_finish(bool const& confirm) {
			struct tm finish = timer->get_current();
			footerf<MAG>();
			logf<LMA>("                         System time: %02i.%02i.%4i %02i:%02i\n", finish.tm_mday, finish.tm_mon+1, finish.tm_year+1900, finish.tm_hour, finish.tm_min);
			footerf<MAG>();
			logf<LGN>("\n  Calculation is successfully finished.\n");
			if(confirm) {
				finish_prompt<LGN>();
				std::cin.get();
			} else {
				logf("\n");
			}
			exit(0);
		}
		inline void print_start() {
			struct tm start = timer->get_start();
			logf<LGN>("   Starting calculation...\n\n");
			footerf<MAG>();
			logf<LMA>("                         System time: %02i.%02i.%4i %02i:%02i\n", start.tm_mday, start.tm_mon+1, start.tm_year+1900, start.tm_hour, start.tm_min);
		}	
	};

	inline void line_feed(int count) {
		if(count<=0) return;
		logf("\n");
		line_feed(--count);
	}
}

#undef LOGFILE
#undef MAX_WARNING
#endif //_LOGGER_H_
