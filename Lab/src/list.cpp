/*!
\file list.cpp
\brief A source code for list data structure
*/
#include "list.h"

List::List(InputFiles& file, Benchmark& listTest){
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

			listTest.test(openFile, this);

			//initial again for next test
			this->~List();
			this->headPtr = nullptr;
			this->tailPtr = nullptr;
			this->tempPtr = nullptr;
			openFile.close();
		}
		//generate raport
		avrgTime = listTest.getAvr(listTest.testTimes);
		listTest.generateRaport(avrgTime, fileSize, fileName, LIST);
	}
}

// A deconstructor
List::~List(){
	headPtr = NULL;
	tailPtr = NULL;
	tempPtr = NULL;

	delete headPtr;
	delete tailPtr;
	delete tempPtr;
}

void List::add(std::fstream& file){
	//container for temporary data
	int tempData;

	//create first node of the list
	file >> tempData;
	this->tailPtr = new LNode(tempData);
	this->headPtr = this->tailPtr;
	this->tempPtr = this->tailPtr;

	while (file >> tempData){
		this->tailPtr = new LNode(tempData);
		this->tempPtr->nextNode = this->tailPtr;
		this->tempPtr = this->tempPtr->nextNode;
	}
}