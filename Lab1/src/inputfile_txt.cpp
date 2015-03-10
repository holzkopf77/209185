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

	std::string TempName;
	for (int i = 0; i < filesNumber; i++){
		TempName = std::tmpnam(nullptr);
		filesNamesTab.push_back(TempName);
	}
	
}

void InputFiles::show_info(){	
	std::cout << "--------" << std::endl;
	std::cout << filesNumber << std::endl;

	for (int i = 0; i < (signed)filesNamesTab.size(); i++){
		std::cout << filesNamesTab[i] << std::endl;
	}
	for (int i = 0; i < (signed)filesSizes.size(); i++){
		std::cout << filesSizes[i] << std::endl;
	}

	std::cout << "--------" << std::endl;
}

