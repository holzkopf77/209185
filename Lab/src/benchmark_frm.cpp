/*!
	\file benchmark_frm.cpp
	\brief Source code for Benchmark class
*/
#include "benchmark_frm.h"

template<class T>
void Benchmark<T>::test(T data_structur, InputFiles& files){
	//new file
	std::fstream file;
	//container for temp value from file
	int tempValue = 0;
	//test time from file
	std::vector<long double> estimateTimes;

	for (int i = 0; i < files.return_number_files() - FIRST_ARGUMENT; i++){
		//do test 10 times for each file
		for (int j = 0; j < 10; j++){
			file.open((files.return_file_name(i) + ".txt"), std::ios::in);
			// Checking if file is opened correctly
			assert(file.is_open() && ("I can't open file."));

			//start test here
			boost::timer::cpu_timer startTime;
			for (int k = 0; k < files.return_file_size(i); k++){
				//****TESTED ALGORITHM****//
				file >> tempValue;
				data_structur.push(tempValue);
			}
			//stop test here
			boost::timer::cpu_times endTime = startTime.elapsed();
			file.close();

			//put new time to the vector
			estimateTimes.push_back(static_cast<long double>(endTime.wall * SEC));
		}
		std::cout.fixed;
		long double finishTestTime = average(estimateTimes);
		avrTestTimes.push_back(finishTestTime);
		std::cout << "Time (average, 10 samples) for " << files.return_file_size(i) << " elements: " << finishTestTime << " sec" << std::endl;
	}
}


template <class T>
long double Benchmark<T>::average(std::vector<long double>times){
	long double avrg = 0.0;

	//add 10 values, than count average
	for (int i = 0; i < (signed)times.size(); i++){
		avrg += times[i];
	}

	avrg /= (long double)times.size();
	return avrg;
}

template<class T>
void Benchmark<T>::raport(InputFiles& files){
	
	std::ofstream raportFile; 
	std::string stringNextTime;
	int fileCount = 0;

	// .xls as excel file format
	raportFile.open("test.xls", std::ios::in | std::ios::app);
	assert(raportFile.is_open() && ("I can't open file."));
	// need to change '.' on ',' due to excel string format 

	for (int i = 0; i < avrTestTimes.size();i++){
		stringNextTime = std::to_string(avrTestTimes[fileCount]);
		boost::algorithm::replace_first(stringNextTime, ".", ",");
		raportFile << files.return_file_size(fileCount) << "\n" << stringNextTime << "\n";
		++fileCount;
	}

	raportFile.close();
}
