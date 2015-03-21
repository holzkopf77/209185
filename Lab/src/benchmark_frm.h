/*! 
\file benchmark_frm.h
\brief A Benchmark class
*/
#ifndef BENCHMARK_FRM_H
#define BENCHMARK_FRM_H

#include <vector>
#include <fstream>

#include <boost\timer\timer.hpp>
#include <boost\chrono\duration.hpp>
#include <boost\algorithm\string\replace.hpp>

#include "inputfile_txt.h"
#include "tree_node.h"

// early classes declarations
class Queue;
class List;
class Stack;

const long double SEC = 0.000000001;

/*! \var data_type
	enum type to describe provided data types:
	binary tree(1), queue(2), linked list(3), stack(4)
*/
enum data_type{
	BIN_TREE = 1,
	QUEUE = 2,
	LIST = 3,
	STACK = 4
};

/*! \class Benchmark
	
	Making a framework for testing inserted data structure.
	Using time to estimate computational complexity.
*/
class Benchmark {
	public:
		/*! \todo templates */

		/*! \fn A default constructor
		*/
		Benchmark();
		
		/* \fn A copy constructor
			\param copy 
		*/
		Benchmark(const Benchmark& copy);

		/*! 
			\fn test
			\brief Main testing function

			Version for dynamic table;

			\param files random generated files with integers
		*/
		void test(InputFiles files);

		/*! 
		\fn test
		\brief Testing function.

		Version for binary tree

		\param file a pointer to the opened file
		\param root a pointer to the root node of the tree
		*/
		void test(std::fstream& file, Node* root);

		/*! 
		\fn test
		\brief Testing function.

		Version for queue

		\param fileSize a size of tested file
		\param openFile a pointer to the opened file
		\param newQueue a pointer to the tested queue
		*/
		void test(int fileSize, std::fstream& openFile, Queue* newQueue);

		/*! \fn test
		\brief Testing function.

		Version for linked list.

		\param fileSize a size of tested file
		\param openFile a pointer to the opened file
		\param newList a pointer to the tested list
		*/
		void test(std::fstream& openFile, List* newList);

		/*! \fn test
		\brief Testing function.

		Version for stack.

		\param fileSize a size of tested file
		\param openFile a pointer to the opened file
		\param newStack a pointer to the tested stack
		*/
		void test(int fileSize, std::fstream& openFile, Stack* newStack);
	
		/*! \fn show_testTimes_v
			\brief show filled vector with test times
		*/
		void show_testTimes_v();

	private:
		/*! \fn measureTime
			\brief Measures the duration of the work of assignment function.

			Version for dynamic table

			\param dataTable A container with random integers from earlier made files.
			\param dataSize A size of the file.
		*/
		void measureTime(int *dataTable, int dataSize);

		/*! \fn getAvr
		\brief Measures the average duration from 10 samples.

		\param times A container with times from tests.
		*/
		long double getAvr(std::vector<long double>times);
		
		/*! \fn generateRaport
		\brief Generates raport with program tests outputs.

		Dynamic table version.

		\param nextTime A new calculated time (for new file size).
		\param Size A size of the currently working file.
		*/
		void generateRaport(long double nextTime, int size);
		
		/*! \fn generateRaport
		\brief Generates raport with program tests outputs.

		Binary tree version

		\param avgTime A new calculated average time for binary tree test.
		\param size A size of the currently working file.
		\param fileName A name of actually opened file.
		*/
		void generateRaport(long double avgTime, int size, std::string fileName, data_type type);

		/*! \var testTimes
			\brief A container for calculated times.
		*/
		std::vector<long double>testTimes;

		//access to getAvr(), generateRaport(), <long double>testTimes
		friend class Tree;
		friend class Queue;
		friend class List;
		friend class Stack;
};
#endif