/*! A benchmark framework class source code */
#include "benchmark_frm.h"

void Benchmark::test(InputFiles Files){
	int* tabForData = NULL;
	int tempValue = 0;
	int count = 0;

	for (int i = 0; i < Files.return_number_files() - FIRST_ARGUMENT; i++){
		tabForData = new int[Files.return_file_size(i)];
		std::fstream NewFile;
		NewFile.open((Files.return_file_name(i) + ".txt"), std::ios::in);
		//! Check if file is opened correctly
		assert(NewFile.is_open() && ("I can't open file."));
		
		for (int j = 0; j < Files.return_file_size(i); j++){
			NewFile >> tempValue;
			tabForData[j] = tempValue;
		}

		boost::timer::auto_cpu_timer t(4);
		for (int k = 0; k < Files.return_file_size(i); k++){
			tabForData[k] *= 2;
		}
		//! Here it ends
		
		NewFile.close();
		delete[] tabForData;
		
	}
}

