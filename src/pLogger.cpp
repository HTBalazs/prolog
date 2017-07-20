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

#include "pLogger.h"

using namespace ProLog;

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
	unsigned int warning_counter = 0;
}