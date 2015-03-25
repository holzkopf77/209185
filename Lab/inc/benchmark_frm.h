/*! 
	\file benchmark_frm.h
	\brief A Benchmark class
*/
#ifndef BENCHMARK_FRM_H
#define BENCHMARK_FRM_H

#include <vector>
#include <cassert>

#include <boost\timer\timer.hpp>
#include <boost\chrono\duration.hpp>
#include <boost\algorithm\string\replace.hpp>

#include "inputfile_txt.h"

/*! \var SEC
	\brief For multiplying
*/
const long double SEC = 0.000000001;

/*! \class Benchmark
	
	Making a framework for testing inserted data structure.
	Using time to estimate computational complexity.
*/
template<class T>
class Benchmark {
public:
	/*! \fn test
		\brief Main testing function

		\param files random generated files with integers
		\param data_structure tested structure
	*/
	void test(T data_structure, InputFiles& files);

	/*! \fn raport
		\brief Create a .xls file (excel) with file sizes and test times 
	*/
	void raport(InputFiles& files);
private:
	/*! \fn average
		\brief get average time from testing (10 probes)
	*/
	long double average(std::vector<long double>times);
	
	/*! \var avrTestTimes
		\brief A container for calculated times.
	*/
	std::vector<long double>avrTestTimes;
};
#endif