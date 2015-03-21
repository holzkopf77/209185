/*!
\file stack.h
\brief Own implementation of stack data structure.
*/
#ifndef STACK_H
#define STACK_H

#include "inputfile_txt.h"
#include "benchmark_frm.h"

/*! \class Stack

	Own implementation of stack.
	As simple as possible.
*/
class Stack{
	public:
		//! A constructor
		/*
			\param file file with random generated int data
			\param stackTest benchmark for testing stack
		*/
		Stack(InputFiles& file, Benchmark& stackTest);
		
		/*! \fn add
			
			Puts new element on the top of the stack

			\param openFile pointer to the actually opened file with random data
			\param fileSize size of actually opened file
		*/
		void add(std::fstream& openFile, int fileSize);
	private:
		/*! \var stackContainer
			Dynamically created table for date from stack.
		*/
		int* stackContainer;

		/*! \var nrOfElement
			Number of actually element from stack. 
		*/
		int nrOfElement;
};
#endif