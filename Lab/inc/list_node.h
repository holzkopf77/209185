/*!	
\file list_node.h
\brief Nodes for list
*/
#ifndef lIST_NODE_H
#define LIST_NODE_H

/*! \class LNode

	An implementation for nodes to the linked list
*/
class LNode{
	public:
		//! A constructor 
		/*
			\param data a container for data insine node
		*/
		LNode(int data);

		//! A deconstructor
		~LNode();

	private:
		/*! \var nodeData
			Container for data inside node.
		*/
		int nodeData;
		/*! \var nextNode
			Pointer to the next node in linked list.
		*/
		LNode* nextNode;

		friend class List;
};

#endif