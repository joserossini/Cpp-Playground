#pragma once 

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <strstream>
#include <vector>


void read_iterator(const std::string & name)
{
    	std::ifstream file(name.c_str(), std::ios::binary);
	std::string str = std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
}

void read_getline(const std::string & name)
{
    	std::string str;
    	std::ifstream file(name.c_str(), std::ios::binary);
	std::getline(file, str, std::string::traits_type::to_char_type(std::string::traits_type::eof()));
}


void read_ostringstream (const std::string & name)
{
	std::ostringstream str;
	std::ifstream file(name.c_str(), std::ios::binary);
	str << file.rdbuf();
}

void read_fsRead (const std::string & name)
{
	std::ifstream file(name.c_str(), std::ios::binary);

	file.seekg(0, std::ios::end);
	std::ifstream::pos_type fileSize = file.tellg();
	file.seekg(0, std::ios::beg);

	char * bytes = new char[fileSize];
	file.read(&bytes[0], fileSize);

	std::string str = std::string(&bytes[0], fileSize);

	delete bytes;
}
