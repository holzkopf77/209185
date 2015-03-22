/*!
	\file list.h
	\brief Own implementation of linked list
*/
#ifndef LIST_H_
#define LIST_H_

#include "list_node.h"

#include <iostream>
#include <cassert>

/*! \class List

	An implementation of linked list.
*/
template<class T>
class List {
public:
	/*!	\fn List
		\brief A default constructor

		Create empty list.
	*/
	List() : headPtr(nullptr), tempPtr(nullptr), tailPtr(nullptr), sizeLst(0) {}

	/*!	\fn ~List
		\brief A deconstructor

		Null for all pointers
		Delete memory.
	*/
	~List(){
		delete_list();
		headPtr = nullptr;
		tailPtr = nullptr;
		tempPtr = nullptr;
		sizeLst = 0;
	}

	/*! \fn push
		\brief Add new node to the END of the list
			
		\param data inserted data into node.
	*/
	void push(T data);

	/*! \fn push_front 
		\brief Add new node to the BEGINING of the list

		\param data inserted data into node
	*/
	void push_front(T data);

	/*! \fn pop
		\brief return data from last element of the list
	*/
	T pop();

	/*! \fn pop_front
	\brief return data from first element of the list
	*/
	T pop_front();

	/*! \fn size
		\brief	return size of the list
	*/
	inline int size() const {
		return sizeLst;
	}

	/*! \fn return_head()
		\brief	return first node
	*/
	const Node<T>* return_head() const{
		return headPtr;
	}

	/*! \fn operator<<
		\brief Overloaded operator << for displaying
	*/
	friend std::ostream& operator<<(std::ostream& out, const List& list){
		if (list.size() == 0)
		{
			out << "List is empty.";
		}
		else{
			for (auto pointer = list.return_head(); pointer != nullptr;){
				out << pointer->get_data() << ' ';
				pointer = pointer->get_nextNode();
			}
		}
		return out;
	}

private:
	/*! \var headPtr
		First element from the list pointer.
	*/
	Node<T>* headPtr;

	/*! \var tempPtr
		Temporary pointer, help for adding new nodes.
	*/
	Node<T>* tempPtr;

	/*! \var tailPtr
		Pointer for last element
	*/
	Node<T>* tailPtr;

	/*! \var size
		Size of the list
	*/
	int sizeLst;
	
	/*! \fn delete_list
		\brief delete all nodes from list
	*/
	void delete_list();
};
#endif