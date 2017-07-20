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

#ifndef _FILE_H_
#define _FILE_H_

#include <cstdarg>
#include <string>

namespace ProLog {
    class pFile final {
    	FILE* file;
    public:
    	pFile()=delete;
    	pFile(std::string const& file_name, std::string const& mode);
    	~pFile();
    	void fprint(char const* fmt, ...);
    	void vfprint(char const* fmt, va_list args);
    };
}

#endif // _FILE_H_
