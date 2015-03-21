/*!
\file benchmark_frm.cpp
\brief Source code for Benchmark class
*/
#include "benchmark_frm.h"
#include "queue.h"
#include "list.h"
#include "stack.h"

//Copy constructor
Benchmark::Benchmark(const Benchmark& copy){
	testTimes = copy.testTimes;
}
//A default constructor
Benchmark::Benchmark(){
	;
}

void Benchmark::test(InputFiles files){
	// temp memory container
	int* tabForData = NULL;
	int tempValue = 0;
	std::fstream newFile;

	for (int i = 0; i < files.return_number_files() - FIRST_ARGUMENT; i++){
		// Opening file + making new table with content
		tabForData = new int[files.return_file_size(i)];
		newFile.open((files.return_file_name(i) + ".txt"), std::ios::in);

		// Checking if file is opened correctly
		assert(newFile.is_open() && ("I can't open file."));

		for (int j = 0; j < files.return_file_size(i); j++){
			newFile >> tempValue;
			tabForData[j] = tempValue;
		}
		newFile.close();

		// Testing time here
		measureTime(tabForData, files.return_file_size(i));
		delete[] tabForData;
	}
}

// BINARY TREE TEST
void Benchmark::test(std::fstream& file, Node* root){
	// temporary data container
	int tempData;

	//here starts timer
	boost::timer::cpu_timer startTime;
	while (file >> tempData)
		root->add(file, tempData);
	//here ends
	boost::timer::cpu_times endTime = startTime.elapsed();

	//put new time to the vector
	this->testTimes.push_back(static_cast<long double>(endTime.wall * SEC));
}

// QUEUE TEST
void Benchmark::test(int fileSize, std::fstream& openFile, Queue* newQueue){

	//here starts timer
	boost::timer::cpu_timer startTime;
	newQueue->add(openFile, fileSize);
	//here ends
	boost::timer::cpu_times endTime = startTime.elapsed();

	//put new time to the vector
	this->testTimes.push_back(static_cast<long double>(endTime.wall * SEC));
}

// LINKED LIST TEST
void Benchmark::test(std::fstream& openFile, List* newList){

	//here starts timer
	boost::timer::cpu_timer startTime;
	newList->add(openFile);
	//here ends
	boost::timer::cpu_times endTime = startTime.elapsed();

	//put new time to the vector
	this->testTimes.push_back(static_cast<long double>(endTime.wall * SEC));
}

// STACK TEST
void Benchmark::test(int fileSize, std::fstream& openFile, Stack* newStack){
	
	//here starts timer
	boost::timer::cpu_timer startTime;
	newStack->add(openFile, fileSize);
	//here ends
	boost::timer::cpu_times endTime = startTime.elapsed();

	//put new time to the vector
	this->testTimes.push_back(static_cast<long double>(endTime.wall * SEC));
}


void Benchmark::generateRaport(long double nextTime, int size){
	/*! \todo FILE OVERWRITING, NEED TO IMPLEMENT NEW NAMES */
	std::ofstream raportFile;
	std::string stringNextTime = std::to_string(nextTime);

	// .xls as excel file format
	raportFile.open("test.xls", std::ios::in | std::ios::app);
		assert(raportFile.is_open() && ("I can't open file."));
	// need to change '.' on ',' due to excel string format 
	boost::algorithm::replace_first(stringNextTime, ".", ",");
	
	raportFile << size << "\n" << stringNextTime << "\n";
	raportFile.close();
}

void Benchmark::generateRaport(long double avgTime, int size, std::string fileName, data_type type){
	std::ofstream raportFile;
	std::string stringNextTime = std::to_string(avgTime);

	if (type == BIN_TREE){
		// .xls as excel file format
		raportFile.open("test_btree.xls", std::ios::in | std::ios::app);
		assert(raportFile.is_open() && ("I can't open file."));
		// need to change '.' on ',' due to excel string format 
		boost::algorithm::replace_first(stringNextTime, ".", ",");

		raportFile << size << "\n" << stringNextTime << "\n";
		raportFile.close();

		std::cout << "(BinaryTree) For file " << "> " << fileName << " <" << " (size: " << size << ")" << " average test time (10 times) was: " << avgTime << std::endl;
	}
	else if (type == QUEUE){
		// .xls as excel file format
		raportFile.open("test_queue.xls", std::ios::in | std::ios::app);
		assert(raportFile.is_open() && ("I can't open file."));
		// need to change '.' on ',' due to excel string format 
		boost::algorithm::replace_first(stringNextTime, ".", ",");

		raportFile << size << "\n" << stringNextTime << "\n";
		raportFile.close();

		std::cout << "(Queue) For file " << "> " << fileName << " <" << " (size: " << size << ")" << " average test time (10 times) was: " << avgTime << std::endl;
	}
	else if (type == LIST){
		// .xls as excel file format
		raportFile.open("test_list.xls", std::ios::in | std::ios::app);
			assert(raportFile.is_open() && ("I can't open file."));
		// need to change '.' on ',' due to excel string format 
		boost::algorithm::replace_first(stringNextTime, ".", ",");

		raportFile << size << "\n" << stringNextTime << "\n";
		raportFile.close();

		std::cout << "(List) For file " << "> " << fileName << " <" << " (size: " << size << ")" << " average test time (10 times) was: " << avgTime << std::endl;
	}
	else if (type == STACK){
		// .xls as excel file format
		raportFile.open("test_stack.xls", std::ios::in | std::ios::app);
		assert(raportFile.is_open() && ("I can't open file."));
		// need to change '.' on ',' due to excel string format 
		boost::algorithm::replace_first(stringNextTime, ".", ",");

		raportFile << size << "\n" << stringNextTime << "\n";
		raportFile.close();

		std::cout << "(Stack) For file " << "> " << fileName << " <" << " (size: " << size << ")" << " average test time (10 times) was: " << avgTime << std::endl;
	}
}

long double Benchmark::getAvr(std::vector<long double>times){
	long double avrg = 0.0;

	//add 10 values, than count average
	for (int i = 0; i < (signed)times.size(); i++){
		avrg += times[i];
	}

	avrg /= (long double)times.size();
	return avrg;
}

void Benchmark::measureTime(int *dataTable, int dataSize){
	// container for counted working times
	std::vector<long double> estimateTimes;

	for (int j = 0; j < 10; j++){
		// Here starts the timer
		boost::timer::cpu_timer startTime;
		for (int i = 0; i < dataSize; i++){
			dataTable[i] *= 2;
		}
		// Here it ends
		boost::timer::cpu_times endTime = startTime.elapsed();
		// add new time to the vector
		estimateTimes.push_back(static_cast<long double>(endTime.wall * SEC));
	}
	// for better display
	std::cout.fixed;
	long double DurTime = getAvr(estimateTimes);
	std::cout << "Time (average, 10 samples) for " << dataSize << " elements: " << DurTime << " sec"<< std::endl;
	generateRaport(DurTime, dataSize);
}

void Benchmark::show_testTimes_v(){
	for (int i = 0; i < (signed)this->testTimes.size(); i++){
		std::cout << testTimes[i] << std::endl;
	}
}