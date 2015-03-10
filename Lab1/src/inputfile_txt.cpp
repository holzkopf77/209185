/*! A new file object class source code */
#include "inputfile_txt.h"

InputFiles::InputFiles(){

	const int UNDEF_VALUE = 1;
	filesNumber = UNDEF_VALUE;

	//TODO: EXCEPTIONS HANDLING
	std::string TempName = std::tmpnam(nullptr);

	filesNamesTab.push_back(TempName);
	filesSizes.push_back(UNDEF_VALUE);
}

InputFiles::InputFiles(int filNr, std::vector<int>filSiz){
	filesNumber = filNr;
	filesSizes = filSiz;
	
	const int PROGRAM_NAME = 1;
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
	const int FIRST_ARGUMENT = 1;

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

