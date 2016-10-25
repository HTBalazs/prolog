/////////////////////////////////////////////////////////////////////////////
// Name:        pFile.h
// Purpose:     pFile class
// Author:      Balázs Tóth
// Modified by:
// Created:     10/07/2016
// Copyright:   (c) ProLog-project
// Licence:     GPL
/////////////////////////////////////////////////////////////////////////////

#ifndef _FILE_H_
#define _FILE_H_

#include <cstdarg>
#include <string>

class pFile final {
	FILE* file;
public:
	pFile()=delete;
	pFile(std::string const& file_name, std::string const& mode);
	~pFile();
	void fprint(char const* fmt, ...);
	void vfprint(char const* fmt, va_list args);
};

#endif // _FILE_H_
