/*!
\file list.h
\brief Own implementation of linked list
*/
#ifndef LIST_H
#define LIST_H

#include "benchmark_frm.h"
#include "inputfile_txt.h"
#include "list_node.h"

/*! \class List

	An implementation of linked list.
*/
class List{
	public:
		//! A constructor
		/*
			\param file generated files with random int data
			\param listTest benchmark for testing list
		*/
		List(InputFiles& file, Benchmark& listTest);

		//! A deconstructor
		~List();

		void add(std::fstream& file);
	private:
		/*! \var headPtr
			First element from the list pointer.
		*/
		LNode* headPtr;

		/*! \var tempPtr
			Temporary pointer, help for adding new nodes.
		*/
		LNode* tempPtr;

		/*! \var tailPtr
			Last element pointer
		*/
		LNode* tailPtr;


};
#endif