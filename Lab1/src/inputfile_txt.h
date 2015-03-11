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
#include <cassert>
#include <ctime>
#include <random>

#include <boost/algorithm/string/erase.hpp>

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
			Adding number of files;
			Generating files names;
			Adding sizes of files;
			Parameters inherit from list of arguments from command prompt

			\param filNr number of files
			\param filSiz sizes of files
		*/
		InputFiles(int filNr, std::vector<int>filSiz);

		//! Show info about files
		/*!
			Display: number of files, names of files, sizes of files
		*/
		void show_info();

		//! Create random integers data into files
		/*
		Generating random integers data (size from filesSizes vector)
		and putting them into files (names from filesNamesTab)
		*/
		void generate_random_int_data();

		//! Return names of files (only for read purpose)
		std::vector<std::string>return_files_names(){
			return filesNamesTab;
		}

		//! Return sizes of files (only for read purpose)
		std::vector<int>return_files_sizes(){
			return filesSizes;
		}

		//! Return number of files
		int return_number_files(){
			return filesNumber;
		}
	private:
		int filesNumber;
		std::vector<std::string>filesNamesTab;
		std::vector<int>filesSizes;
};	
#endif