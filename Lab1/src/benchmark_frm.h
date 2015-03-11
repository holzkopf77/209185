/*! \file benchmark.h
	\brief A benchmark for framework class
*/
#ifndef BENCHMARK_FRM_H_
#define BENCHMARK_FRM_H_

#include <vector>
#include <fstream>

#include <boost\timer\timer.hpp>

#include "inputfile_txt.h"

/*! \class Benchmark
	
	Making a framework for testing inserted data structure.
	Using time to estimate computational complexity.
*/
class Benchmark {
	public:
		void test(InputFiles files);
	private:
		void measureTime(int *dataTable, int dataSize);
		std::vector<long double>testTimes;
};

#endif