/*!	
\file stack.cpp
\brief A stack class source code.
*/
#include "stack.h"

// A constructor
Stack::Stack(InputFiles& file, Benchmark& stackTest){
	// open file for data in root
	std::fstream openFile;
	// take name of this file
	std::string fileName;
	// file size
	int fileSize;
	// average time from test
	long double avrgTime;

	for (int i = 0; i < file.return_number_files() - FIRST_ARGUMENT; i++){
		fileName = file.return_file_name(i);
		fileSize = file.return_file_size(i);
		for (int i = 0; i < 10; i++){
			openFile.open(fileName + ".txt");
			// Check if file is opened correctly
			assert(openFile.is_open() && "I can't open this file.");
			
			this->stackContainer = new int[fileSize];
			this->nrOfElement = 0;
			stackTest.test(fileSize, openFile, this);

			//initial again for next test
			delete this->stackContainer;
			this->nrOfElement = 0;
			openFile.close();
		}
		//generate raport
		avrgTime = stackTest.getAvr(stackTest.testTimes);
		stackTest.generateRaport(avrgTime, fileSize, fileName, STACK);
	}
}

void Stack::add(std::fstream& openFile, int fileSize){
	//container for temporary data
	int tempData;

	//take first element
	openFile >> tempData;
	this->stackContainer[this->nrOfElement];

	while (openFile >> tempData){
		this->nrOfElement += 1;
		if (this->nrOfElement >= fileSize){
			std::cout << "STACK OVERFLOW OMG OMG OMG NOSCOPE M8" << std::endl;
		}
		else{
			this->stackContainer[this->nrOfElement] = tempData;
		}
	}
}