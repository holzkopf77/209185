/*! \file inputfile_txt.h
	\brief A new input files class
*/
#ifndef INPUTFILE_TXT_H_
#define INPUTFILE_TXT_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <random>

#include <boost/algorithm/string/erase.hpp>

//! First argument from command prompt (name of the program)
const int FIRST_ARGUMENT = 1;
const int UNDEF_VALUE = 1;
const int PROGRAM_NAME = 1;

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
		/*!
			\param Nmbr number of the file
		*/
		const std::string return_file_name(int Nmbr){
			return filesNamesTab[Nmbr];
		}

		//! Return sizes of files (only for read purpose)
		/*!
			\param Nmbr number of the file
		*/
		const int return_file_size(int Nmbr){
			return filesSizes[Nmbr];
		}

		//! Return number of files
		const int return_number_files(){
			return filesNumber;
		}
	private:
		int filesNumber;
		std::vector<std::string>filesNamesTab;
		std::vector<int>filesSizes;
};	
#endif