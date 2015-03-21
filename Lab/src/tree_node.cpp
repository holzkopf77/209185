/*! 
\file tree_node.cpp
\brief A source file for Node class.
*/
#include "tree_node.h"

// constuctor for root node
Node::Node(int data){
	data_container = data;
	parent = NULL;
	left = NULL;
	right = NULL;
	is_empty = false;
}

// constructor for child nood
Node::Node(int data, Node* parent_ptr){
	data_container = data;
	parent = parent_ptr;
	left = NULL;
	right = NULL;
	is_empty = false;
}

// deconstructor 
Node::~Node(){
	delete this->left;
	delete this->right;
}

void Node::add(std::fstream& openFile, int tempData){
	// algorithm described in header file
	if (this->data_container >= tempData){
		if (this->left == NULL){
			this->left = new Node(tempData, this->parent);
		}
		else{
			this->left->add(openFile, tempData);
		}
	}
	else{
		if (this->right == NULL){
			this->right = new Node(tempData, this->parent);
		}
		else{
			this->right->add(openFile, tempData);
		}
	}
}
