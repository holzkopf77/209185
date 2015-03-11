/*! A benchmark framework class source code */
#include "benchmark_frm.h"

void Benchmark::measureTime(int *dataTable, int dataSize){
	//! Here starts the timer
	boost::timer::auto_cpu_timer t;
	for (int i = 0; i < dataSize; i++){
		dataTable[i] *= 2;
	}
	//! Here it ends
}

void Benchmark::test(InputFiles files){
	int* tabForData = NULL;
	int tempValue = 0;
	int count = 0;
	std::fstream newFile;

	for (int i = 0; i < files.return_number_files() - FIRST_ARGUMENT; i++){
		
		//! Opening file + making new table with content
		tabForData = new int[files.return_file_size(i)];
		newFile.open((files.return_file_name(i) + ".txt"), std::ios::in);
		
		//! Check if file is opened correctly
		assert(newFile.is_open() && ("I can't open file."));

		for (int j = 0; j < files.return_file_size(i); j++){
			newFile >> tempValue;
			tabForData[j] = tempValue;
		}
		newFile.close();

		//! Testing time here
		measureTime(tabForData, files.return_file_size(i));
		delete[] tabForData;
		
	}
}

