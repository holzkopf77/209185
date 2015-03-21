/*! \file inputfile_txt.h
	\brief A InputFile class
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

const int FIRST_ARGUMENT = 1; //!< A const value for representing first argument from command prompt (name of the program) */
const int UNDEF_VALUE = 1; //!<  A value for undefined arguments */
const int PROGRAM_NAME = 1; //!< The same as FIRST_ARGUMENT */

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

		/*! \fn show_info()
			\brief Showes info obout files.

			Display: number of files, names of files, sizes of files
		*/
		void show_info();

		/*! \fn generate_random_int_data
			\brief Puts random int data into files.

			Generating random integers data (size from filesSizes vector)
			and putting them into files (names from filesNamesTab)
		*/
		void generate_random_int_data();

		/*! \fn return_file_name
			\brief Return names of files (only for read purpose)
			\param Nmbr Number of the file.
		*/
		const std::string return_file_name(int Nmbr){
			const std::string NAME = filesNamesTab[Nmbr];
			return NAME;
		}

		/*! \fn return_file_size
			\brief Return sizes of files (only for read purpose)
			\param Nmbr Number of the file.
		*/
		const int return_file_size(int Nmbr){
			return filesSizes[Nmbr];
		}

		/*! \fn return_number_files
			\brief Return number of files
		*/
		const int return_number_files(){
			return filesNumber;
		}
	private:
		/*! \var filesNumber
			\brief Number of generated files
		*/
		int filesNumber;

		/*! \varfilesNamesTab
			\brief Container for generated file names
		*/
		std::vector<std::string>filesNamesTab;

		/*! \var filesSizes
			\brief Container for file sizes
		*/
		std::vector<int>filesSizes;
};	
#endif