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
char NRM[] = "\x1B[0m";
char RED[] = "\x1B[31m";
char GRN[] = "\x1B[32m";
char YEL[] = "\x1B[33m";
char BLU[] = "\x1B[34m";
char MAG[] = "\x1B[35m";
char CYN[] = "\x1B[36m";
char LGY[] = "\x1B[37m";
char DGY[] = "\x1B[90m";
char LRD[] = "\x1B[91m";
char LGN[] = "\x1B[92m";
char LYW[] = "\x1B[93m";
char LBL[] = "\x1B[94m";
char LMA[] = "\x1B[95m";
char LCY[] = "\x1B[96m";
char WHT[] = "\x1B[97m";

namespace pLogger {
	std::string logfile = "sim.log";
	unsigned int max_warning = 10;
}