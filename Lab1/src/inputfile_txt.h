/*! \file inputfile_txt.h
	\brief A new input files class
*/
#ifndef inputfile_txt
#define inputfile_txt

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
/*! \class InputFiles

	Making an object which contain text files with 
	generated random integer numbers.
*/
class InputFiles {	
	public:
		//! A default constructor
		/*!
			Adding number of files(UNDEF_VALUE = 1);
			Generating file name;
			Adding size of file (UNDEF_VALUE = 1);

			Just in case, when program starts without any parameters.
		*/
		InputFiles();
		
		//! A constructor
		/*!
			Adding number of files(1);
			Generating files names(1);
		*/
		InputFiles(int filNr, std::vector<int>filSiz);

		//! Show info about files
		std::string show_info();
	private:
		int filesNumber;
		std::vector<std::string>filesNamesTab;
		std::vector<int>filesSize;
};
#endif