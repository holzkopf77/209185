/*!
	\file tree_node.h
	\brief Own implementation of tree data structure (Node of tree)
*/
#ifndef TREE_NODE_H_
#define TREE_NODE_H_

/*! \class Node
	Binary tree nodes implementation.
*/
template<class T>
class NodeB{
public:
	/*! \fn NodeB
		\brief A constructor

		Create empty node.
		Every pointer is NULL.
		root data = 0;
	*/
	NodeB() : parent(nullptr), left(nullptr), right(nullptr), empty(true), data(T(0)) {}

	/*! \fn NodeB
	\brief A constructor

	Create empty NodeB.
	Every pointer is NULL.

	\param data inserted data from argument
	*/
	NodeB(T data) : parent(nullptr), left(nullptr), right(nullptr), empty(true), data(T(data)) {}
	
	/*! \fn ~NodeB 
		\brief A destructor

		Free all memory.
		Deleting this pointer, so it's dangerous.
	*/
	~NodeB(){
		if (left!=nullptr)
			delete left;
		if (right != nullptr)
			delete right;
		//if (parent != nullptr)
		//	delete parent;
		left = nullptr;
		right = nullptr;
		data = 0;
	}

	/*! \fn get_data_c
		\brief return const value of date from node
	*/
	inline T get_data(){
		return data;
	}

	/*! \fn return_left
	\brief return pointer to the left branch of node
	*/
	inline NodeB<T>* return_left(){
		return left;
	}

	/*! \fn return_right
		\brief return pointer to the right branch of node
	*/
	inline NodeB<T>* return_right(){
		return right;
	}

	/*! \fn return_parent
		\brief return pointer to the parent  of node
	*/
	inline NodeB<T>* return_parent(){
		return parent;
	}

	/*! \fn is_empty
		\brief return state of node

		true - empty NodeB
		false - not empty NodeB
	*/
	inline const bool is_empty(){
		return empty;
	}
	
	//access to the private part
	template<class T>
	friend class Tree;

private:
	/*! \var parent
		\brief link with parent node from tree
	*/
	NodeB<T>* parent;

	/*! \var left
		\brief link with left branch node from parent

		Data smaller than parent data.
	*/
	NodeB<T>* left;

	/*! \var right
		\brief link with right branch node from parent

		Data bigger than parent data.
	*/
	NodeB<T>* right;

	/*! \var empty 
		Flag for empty(true)/nonempty node(false)
	*/
	bool empty;

	/*! \var data
		\brief Container for random integer data
	*/
	T data;
};
#endif