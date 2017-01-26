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

#include <iostream>
#include <fstream>
#include <memory>
#include <cstdarg>
#include <stdio.h>
#include <string.h>
#include "pTimer.h"
#include "pFile.h"

#if defined(__linux__) || defined(__APPLE__)
#define USECOLOURS
#endif // __linux__ __APPLE__

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
	extern std::string logfile;
	extern unsigned int max_warning;

	inline bool already_written() {
		static bool written = false;
		if(!written) {
			written = true;
			return false;
		}
		return true;
	}

	inline void to_file(char const* fmt, va_list args) {
		pFile file{logfile.c_str(), already_written()?"a":"w"};
		file.vfprint(fmt, args);
	}

	template <char const* color> void log(char const* fmt, va_list args) {
	#ifdef USECOLOURS
		printf("%s", color);
	#endif //USECOLOURS
		vprintf(fmt, args);
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
		if(max_warning<counter) {
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
		if(max_warning<counter) {
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



	inline void line_feed(int count) {
		if(count<=0) return;
		logf("\n");
		line_feed(--count);
	}
}

#endif //_LOGGER_H_
