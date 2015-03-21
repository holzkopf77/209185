/*!	
\file list_node.cpp
\brief A source code for LNode class.
*/
#include "list_node.h"

// a constructor
LNode::LNode(int data){
	this->nodeData = data;
	this->nextNode = nullptr;
}

// a deconstructor
LNode::~LNode(){
	this->nextNode = nullptr;
	delete this->nextNode;
}