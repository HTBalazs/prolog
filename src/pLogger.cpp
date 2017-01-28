////////////////////////////////////////////////////////////////////////////
// Name:        pLogger.cpp
// Purpose:     pLogger namespace
// Author:      Balázs Tóth
// Modified by:
// Created:     10/07/2016
// Copyright:   (c) ProLog-project
// Licence:     GPL
/////////////////////////////////////////////////////////////////////////////

#include "pLogger.h"

/** Global definition of colors.
*/
char NRM[] = "\033[0m";
char RED[] = "\033[31m";
char GRN[] = "\033[32m";
char YEL[] = "\033[33m";
char BLU[] = "\033[34m";
char MAG[] = "\033[35m";
char CYN[] = "\033[36m";
char LGY[] = "\033[37m";
char DGY[] = "\033[90m";
char LRD[] = "\033[91m";
char LGN[] = "\033[92m";
char LYW[] = "\033[93m";
char LBL[] = "\033[94m";
char LMA[] = "\033[95m";
char LCY[] = "\033[96m";
char WHT[] = "\033[97m";

namespace pLogger {
	std::string logfile = "sim.log";
	unsigned int max_warning = 10;
	unsigned int warning_counter = 10;
}