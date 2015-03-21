/*! 
\file main.cpp
\brief A master file
*/
#include <iostream>

#include "inputfile_txt.h"
#include "stack.h"
#include "stack.cpp"

int main(int argc, char* argv[]){
	
	// contains only one size, implementation from Lab1
	std::vector<int>fileSize;
	// First argument is a name of the program so i = 1
	for (int i = 1; i < argc; i++)
		fileSize.push_back(atoi(argv[i]));
	
	InputFiles openFile(argc, fileSize);
	openFile.generate_random_int_data();

	std::cin.get();
	return 0;
}