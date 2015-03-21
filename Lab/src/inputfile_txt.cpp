/*! \file inputfile_txt.cpp
	\brief Source code for InputFile class
*/
#include "inputfile_txt.h"

InputFiles::InputFiles(){
	/*! \todo EXCEPTIONS HANDLING */
	// When there are no arguments from command prompt:
	filesNumber = UNDEF_VALUE;
	std::string TempName = std::tmpnam(nullptr);
	filesNamesTab.push_back(TempName);
	filesSizes.push_back(UNDEF_VALUE);
}

InputFiles::InputFiles(int filNr, std::vector<int>filSiz){
	filesNumber = filNr;
	filesSizes = filSiz;
	// Create new names for files
	std::string TempName;

	for (int i = 1; i < filesNumber; i++){
		// Generate new unique name for file
		TempName = std::tmpnam(nullptr);
		// Delete all prohibit char from string
		boost::algorithm::erase_all(TempName, "/");
		boost::algorithm::erase_all(TempName, "\\");
		// Put name into names container
		filesNamesTab.push_back(TempName);
	}
	//! Open files with new names
	std::ofstream newFile;
	for (int i = 1; i < filesNumber; i++){
		newFile.open(filesNamesTab[i - PROGRAM_NAME] + ".txt");
			//! Check if file is opened correctly
			assert(newFile.is_open() && "I can't open this file.");
		newFile.close();
	}
}

void InputFiles::show_info(){	
	std::cout << "--------" << std::endl;
	std::cout << filesNumber - FIRST_ARGUMENT << std::endl;
	for (int i = 0; i < (signed)filesNamesTab.size(); i++){
		std::cout << filesNamesTab[i] << std::endl;
	}
	for (int i = 0; i < (signed)filesSizes.size(); i++){
		std::cout << filesSizes[i] << std::endl;
	}
	std::cout << "--------" << std::endl;
}

void InputFiles::generate_random_int_data(){
	int seedGen = time(NULL); /*!< Seed for Mersenne Twister 19937 generator */

	//! Mersenne Twister 19937 generator
	/*!
		More info about this generator:
		<a href="linkURL">http://pl.wikipedia.org/wiki/Mersenne_Twister</a> 
	*/
	std::mt19937 randomNumbr(seedGen);

	//! Uniform distribution random number
	/*!
		Max number: uncomment next line
		More info about this distribution:
		<a href="linkURL">http://pl.wikipedia.org/wiki/Rozk%C5%82ad_jednostajny</a>
	*/
	//std::cout << std::numeric_limits<int>::max() << std::endl;
	std::uniform_int_distribution<>newDistr(0,9999);

	std::ofstream NewFile;
	for (int i = 1; i < filesNumber; i++){
		NewFile.open((filesNamesTab[i - PROGRAM_NAME] + ".txt"), std::ios::in);
			//! Check if file is opened correctly
			assert(NewFile.is_open() && ("I can't open file."));
		//Generate random int data
		for (int j = 0; j < filesSizes[i - FIRST_ARGUMENT]; j++){
			NewFile << newDistr(randomNumbr) << "\n";
		}

		NewFile.close();
	}
}

