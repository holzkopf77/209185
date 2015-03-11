/*! \file benchmark.h
	\brief A benchmark for framework class
*/
#ifndef benchmark_frm
#define benchmark_frm

#include <vector>
#include "inputfile_txt.h"
/*! \class Benchmark
	
	Making a framework for testing inserted data structure.
	Using time to estimate computational complexity.
*/
class Benchmark {
	public:
		void Test(InputFiles Files);
	private:
		std::vector<long double>TestTimes;
		

};




#endif