/*!	
	\file tree.h
	\brief Own implementation of tree data structure.
*/
#ifndef TREE_H_
#define TREE_H_

#include <cassert>

#include "tree_node.h"

/*! \class Tree
	
	Own binary tree class, based on information from book: "Data structure and algorithms in C++"- Goodrich
	Time tested in constructor.
*/
template<class T>
class Tree{
public:
	/*! \fn Tree
		\brief A constructor (default)

		Create tree with only root node ( init with 0 in this type constructor)
	*/
	Tree() : root(new NodeB<T>()), sizeTre(0), empty(true) {}

	/*! \fn Tree
		\brief A constructor

		Create tree with only root node ( init with data from argument)
		\param data new data inserted to the node
	*/
	Tree(T data) : root(new NodeB<T>(data)), sizeTre(1), empty(false) {}

	/*! \fn ~Tree
		\brief A destructor

		Delete all nodes, all pointers = NULL;
	*/
	//~Tree();

	/*! \fn push
		\brief add new node to the tree

		\param data new data inserted to the node
	*/
	void push(T data);

	/*! \fn pop
		\brief delete node with data from argument, than return data from this node

		Find data inside the tree than delete node with it, reorganize the tree.
		If pop from tree with size = 1, return value from root node, than set it to 0.

		\param data element with data will be deleted
	*/
	T pop(T data);

	/*! \fn show_tree
		\brief show 3 levels from tree, starting from root node.
	*/
	void show_tree();

	/*! \fn is_empty
		\brief return info if the tree is empty
	*/
	const bool is_empty(){
		return empty;
	}

	/*! \fn size
		\brief return size of the tree
	*/
	const int size(){
		return sizeTre;
	}

private:
	/*! \var root
		\brief Root node of the tree.
	*/
	NodeB<T>* root;

	/*! \var sizeTre
		\brief Quantity of nodes from the tree (with root node)

		if root node has default value = 0 <- sizeTre = 0
	*/
	int sizeTre;

	/*! \var empty
		
		True - tree has only default root node with 0;
		False - tree has something inside
	
		if there is only init root node with something from user, still false
	*/
	bool empty;
};
#endif