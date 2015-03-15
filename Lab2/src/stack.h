/*!	\file stack.h
	\brief A stack class file.
*/
#include <iostream>

/*!	\class Stack
	\brief Own implementation of stack data structure.

	Own stack implementation based on dynamically created table.
	Size of this data structure is defined in the argument from
	console while starting program.
*/
class Stack{
	public:
		//! A default constructor 	
		Stack(int stackSize);

	private:
		int* stack = NULL;
};