/*! \file benchmark.h
	\brief A benchmark for framework class
*/
#ifndef benchmark_frm
#define benchmark_frm

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
		void test(InputFiles Files);
	private:
		std::vector<long double>testTimes;
};




#endif