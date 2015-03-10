/*! A new file object class source code */
#include "inputfile_txt.h"

InputFiles::InputFiles(){

	const int UNDEF_VALUE = 1;
	filesNumber = UNDEF_VALUE;

	//TODO: EXCEPTIONS HANDLING
	std::string TempName = std::tmpnam(nullptr);

	filesNamesTab.push_back(TempName);
	filesSize.push_back(UNDEF_VALUE);
}

std::string InputFiles::show_info(){
	std::cout << "--------" << std::endl;
	std::cout << filesNumber << std::endl;
	std::cout << filesNamesTab[0] << std::endl;
	std::cout << filesSize[0] << std::endl;
	std::cout << "--------" << std::endl;
}

