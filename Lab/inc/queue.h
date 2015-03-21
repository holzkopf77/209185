/*!	
\file queue.h
\brief Own implementation of queue.
*/
#ifndef QUEUE_H
#define QUEUE_H


#include "inputfile_txt.h"
#include "benchmark_frm.h"


/*! \class Queue

	An implementation of queue based on dynamically created table. 
	Info based on http://www.studytonight.com/data-structures/queue-data-structure
*/
class Queue {
	public:
		//! A constructor
		/*
			\param file generated files with int random data
			\param queueTest a benchmark for queue
		*/
		Queue(InputFiles& file, Benchmark& queueTest);

		//! A deconstructor
		~Queue();

		/*! \fn add
		\brief Adding new element to the rear part of queue

		Adding new element, on the rear part, move this pointer to the next element.

		\param openFile a pointer to the opened file
		\param fileSize a size of opened file
		*/
		void add(std::fstream& openFile, int fileSize);
	private:
		/*! \var queueTab

			A dynamic container for elements of queue
		*/
		int* queueTab;
		/*! \var rear

			A tail of queue position
		*/
		int rear;

		/*! \var front

			A head of queue position
		*/
		int front;

};

#endif