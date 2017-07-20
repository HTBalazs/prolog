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

#include "pFile.h"

using namespace ProLog;

/////////////////////////////////////////////////////////////////////////////////////////
/// Constructor.
/////////////////////////////////////////////////////////////////////////////////////////
pFile::pFile(std::string const& filename, std::string const& mode) {
	file = fopen(filename.c_str(), mode.c_str());
}

/////////////////////////////////////////////////////////////////////////////////////////
/// Destructor.
/////////////////////////////////////////////////////////////////////////////////////////
pFile::~pFile() {
	fclose(file);
}

/////////////////////////////////////////////////////////////////////////////////////////
/// Implements fprintf.
/////////////////////////////////////////////////////////////////////////////////////////
void pFile::fprint(char const* fmt, ...) {
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);
}

/////////////////////////////////////////////////////////////////////////////////////////
/// Implements vfprintf.
/////////////////////////////////////////////////////////////////////////////////////////
void pFile::vfprint(char const* fmt, va_list args) {
	vfprintf(file,fmt,args);
}
