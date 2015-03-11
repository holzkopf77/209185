/*! A new file object class source code */
#include "inputfile_txt.h"

//! First argument from command prompt (name of the program)
const int FIRST_ARGUMENT = 1;
const int UNDEF_VALUE = 1;
const int PROGRAM_NAME = 1;

InputFiles::InputFiles(){
	filesNumber = UNDEF_VALUE;

	//TODO: EXCEPTIONS HANDLING
	std::string TempName = std::tmpnam(nullptr);

	filesNamesTab.push_back(TempName);
	filesSizes.push_back(UNDEF_VALUE);
}

InputFiles::InputFiles(int filNr, std::vector<int>filSiz){
	filesNumber = filNr;
	filesSizes = filSiz;
	
	//! Create new names for files
	std::string TempName;
	for (int i = 1; i < filesNumber; i++){
		TempName = std::tmpnam(nullptr);

		//! Delete all prohibit char from string
		boost::algorithm::erase_all(TempName, "/");
		boost::algorithm::erase_all(TempName, "\\");

		filesNamesTab.push_back(TempName);
	}

	//! Open files with new names
	std::ofstream NewFile;
	for (int i = 1; i < filesNumber; i++){
		NewFile.open(filesNamesTab[i - PROGRAM_NAME] + ".txt");
		//! Check if file is opened correctly
		assert(NewFile.is_open() && "I can't open this file.");
		NewFile.close();
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
	std::ofstream NewFile;

	//! Seed for Mersenne Twister 19937 generator
	int seedGen = time(NULL);

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
	std::uniform_int_distribution<>newDistr;

	for (int i = 1; i < filesNumber; i++){
		NewFile.open((filesNamesTab[i - PROGRAM_NAME] + ".txt"),std::ios::in);
		//! Check if file is opened correctly
		assert(NewFile.is_open() && ("I can't open file."));
		for (int j = 0; j < filesSizes[i - FIRST_ARGUMENT]; j++){
			NewFile << newDistr(randomNumbr) << "\n";
		}
		NewFile.close();
	}
}

