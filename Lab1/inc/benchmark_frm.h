/*! \file benchmark_frm.h
	\brief A Benchmark class
*/
#ifndef BENCHMARK_FRM_H_
#define BENCHMARK_FRM_H_

#include <vector>
#include <fstream>

#include <boost\timer\timer.hpp>
#include <boost\chrono\duration.hpp>
#include <boost\algorithm\string\replace.hpp>

#include "tree_node.h"
#include "inputfile_txt.h"

const long double SEC = 0.000000001;

/*! \class Benchmark
	
	Making a framework for testing inserted data structure.
	Using time to estimate computational complexity.
*/
class Benchmark {
	public:
		/*! \fn test
			\brief Main testing function

			\param files random generated files with integers
		*/
		void test(InputFiles files);
	private:
		/*! \fn measureTime
			\brief Measures the duration of the work of assignment function.

			Version for dynamic tables.

			\param dataTable A container with random integers from earlier made files.
			\param dataSize A size of the file.
		*/
		void measureTime(int *dataTable, int dataSize);
		
		void measureTime(InputFiles& file, Node* root)







		/*! \fn getAvr
		\brief Measures the average duration from 10 samples.

		\param times A container with times from tests.
		*/
		long double getAvr(std::vector<long double>times);
		
		/*! \fn generateRaport
		\brief Generates raport with program tests outputs.

		\param nextTime A new calculated time (for new file size).
		\param Size A size of the currently working file.
		*/
		void generateRaport(long double nextTime, int size);
		
		/*! \var testTimes
			\brief A container for calculated times.
		*/
		std::vector<long double>testTimes;
};
#endif