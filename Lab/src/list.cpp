/*!
\file list.cpp
\brief A source code for list data structure
*/
#include "list.h"
template<class T>
void List<T>::push(T data){
	// first element to the list
	if (sizeLst == 0){
		tailPtr = new Node<T>(data);
		headPtr = tailPtr;
		tempPtr = tailPtr;
		sizeLst++;
	}
	else{
		tempPtr = tailPtr;
		tailPtr = new Node<T>(data);
		tempPtr->nextNode = tailPtr;
		tempPtr = tailPtr;
		sizeLst++;
	}
}

template<class T>
void List<T>::push_front(T data){
	// first element to the list
	if (sizeLst == 0){
		tailPtr = new Node<T>(data);
		headPtr = tailPtr;
		tempPtr = tailPtr;
		sizeLst++;
	}
	else{
		//insert element as the first element
		tempPtr = headPtr;
		headPtr = new Node<T>(data);
		headPtr->nextNode = tempPtr;
		tempPtr = headPtr;
		sizeLst++;
	}
}

template<class T>
T List<T>::pop(){
	assert(sizeLst > 0 && "You are trying to delete from empty list");
	int counter = 0;
	T nodeData;
	auto pointer = headPtr;

	// go through the list, stop when we've got second elemnt from end
	while (counter < (sizeLst - 2)){
		pointer = pointer->nextNode;
		counter++;
	}

	tailPtr = pointer;
	tailPtr->nextNode = nullptr;
	nodeData = tempPtr->get_data();
	delete tempPtr;
	tempPtr = tailPtr;
	sizeLst--;

	return nodeData;
}

template<class T>
T List<T>::pop_front(){
	assert(sizeLst > 0 && "You are trying to delete from empty list");
	auto pointer = headPtr;
	T nodeData = headPtr->get_data();
	headPtr = pointer->nextNode;
	pointer->nextNode = nullptr;
	delete pointer;
	sizeLst--;
	return nodeData;
}

template<class T>
void List<T>::delete_list(){
	int counter = sizeLst;
	auto pointer = headPtr;
	//delete all nodes
	while (counter > 0){
		if (pointer->get_nextNode() == nullptr){
			pointer->~Node();
			counter--;
		}
		else{
			pointer = pointer->nextNode;
		}
	}
}