/*! \file benchmark_frm.cpp
	\brief Source code for Benchmark class
*/
#include "benchmark_frm.h"

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

void Benchmark::test(InputFiles files){
	// temp memory container
	int* tabForData = NULL;
	int tempValue = 0;
	int count = 0;
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

