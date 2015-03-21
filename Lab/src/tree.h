/*!	
\file tree.h
\brief Own implementation of tree data structure.
*/
#ifndef TREE_H
#define TREE_H

#include "tree_node.h"
#include "inputfile_txt.h"
#include "benchmark_frm.h"

/*! \var FIRST_FILE
	const int for first file index
*/
const int FIRST_FILE = 0;

/* \class Tree
	Own binary tree class, based on information from book: "Data structure and algorithms in C++"- Goodrich
	Time tested in constructor.
*/
class Tree{
	public:
		//! constructor
		/*!
			Open file with random integers (range: 0 - 99999), create root node, than add new branch nodes depends on
			data from file.
		*/
		Tree(InputFiles& file, Benchmark& TreeTest);

		//! deconstructor
		/*!
			Empty all memory space for tree
		*/
		~Tree();

		/*! \fn show_tree
			\brief show 3 levels from tree, starting from root node. 
		*/
		void show_tree();
	private:
		/*! \var root
			\brief Root node of the tree.
		*/
		Node* root;
};
#endif