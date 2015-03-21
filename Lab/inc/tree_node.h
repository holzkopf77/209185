/*!
\file tree_node.h
\brief Own implementation of tree data structure (nodes of tree)
*/
#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <vector>
#include <fstream>

/* \class Node
	Binary tree nodes implementation.
*/
class Node{
	public:
		//! root constructor
		/*
			Only adding first data from file to data_container.
			Every pointer is NULL.
		*/
		Node(int data);

		//! child constructor
		/*
			Adding data to data_container
			Parent pointer init with parent object pointer.
		*/
		Node(int data, Node* parent_ptr);

		//! deconstructor
		/*
			Free all memory.
			Deleting this pointer, so it's dangerous.
		*/
		~Node();

		/*! \fn get_data_container
			\brief return value of date from node
		*/
		inline const int get_data_container(){
			return data_container;
		}

		/*! \fn return_left
		\brief return pointer to the left branch of node
		*/
		inline Node* return_left(){
			return left;
		}

		/*! \fn return_right
		\brief return pointer to the right branch of node
		*/
		inline Node* return_right(){
			return right;
		}

		/*! \fn is_emptyf
			\brief return state of node

			true - empty node
			false - not empty node
		*/
		bool is_emptyf(){
			return is_empty;
		}

		/*! \fn add
			\brief adding new branch nodes to the parent node

			!! This is a recursive function.!!
			End point: when file is ended.
			Open file with random int data, check if there is open left/right branch node from parent:
			Algorithm:
			add(openFile,dataFromFile){
				if rootData is bigger or equal dataFromFile
					if thereIsLeftNode
						add(openFile,datafromFile) // opening new node
					else
						create leftNode and add data
				if rootData is smaller than dataFromFile
					if thereisRightNode
						add(openFile,datafromFile) // opening new node
					else
						create rightNode and add data

			\param openFile actually opened file with random int data
			\param tempData container for data from file
		*/
		void add(std::fstream& openFile,int tempData);

	private:
		/*! \var parent
			\brief link with parent node from tree
		*/
		Node* parent;

		/*! \var left
			\brief link with left branch node from parent

			Data smaller than parent data.
		*/
		Node* left;

		/*! \var right
			\brief link with right branch node from parent

			Data bigger than parent data.
		*/
		Node* right;

		/*! \var is_empty */
		bool is_empty;

		/*! \var data_container
			\brief Container for random integer data
		*/
		int data_container;
};
#endif