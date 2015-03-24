/*! 
	\file main.cpp
	\brief A master file
*/
#include <iostream>

#include "inputfile_txt.h"
#include "stack.h"
#include "list.h"
#include "queue.h"
#include "tree.h"

#include "list.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "tree.cpp"

int main(int argc, char* argv[]){
	
	// contains only one size, implementation from Lab1
	std::vector<int>fileSize;
	// First argument is a name of the program so i = 1
	for (int i = 1; i < argc; i++)
		fileSize.push_back(atoi(argv[i]));
	
	InputFiles openFile(argc, fileSize);
	openFile.generate_random_int_data();

	Tree<int> tree;
	std::cin.get();
	return 0;
}