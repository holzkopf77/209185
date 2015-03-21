/*!	
\file queue.spp
\brief A source code for Queue class
*/
#include "inputfile_txt.h"
#include "benchmark_frm.h"
#include "queue.h"

// constructor
Queue::Queue(InputFiles& file, Benchmark& queueTest){
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

			this->queueTab = new int[fileSize];
			this->front = 0;
			this->rear = 0;

			queueTest.test(fileSize, openFile, this);

			//initial again for next test
			this->~Queue();
			this->front = 0;
			this->rear = 0;
			openFile.close();
		}
		//generate raport
		avrgTime = queueTest.getAvr(queueTest.testTimes);
		queueTest.generateRaport(avrgTime, fileSize, fileName, QUEUE);
	}
}

//deconstructor
Queue::~Queue(){
	//clear everything
	queueTab = NULL;
	delete[] queueTab;
}



void Queue::add(std::fstream& openFile, int fileSize){
	// temporary data container
	int tempData;
	int counter = 0;

	while (openFile >> tempData){
		counter++;
		//check if there is some place in queue
		if (counter > fileSize){
			std::cout << " Queue is full! Program is going to be terminated" << std::endl;
			std::cin.get();
			exit(true);
		}
		else{
			if (this->rear)
				// add element on the rear part of queue
				this->queueTab[this->rear] = tempData;
			// move rear poiner
			// if it move behind queue, make it on the front.
			this->rear = (this->rear + 1) % fileSize;
		}
	}
}