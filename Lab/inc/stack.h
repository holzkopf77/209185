/*!
\file stack.h
\brief Own implementation of stack data structure.
*/
#ifndef STACK_H
#define STACK_H

#include <vector>
#include <cassert>
/*! \class Stack

	Own implementation of stack.
	As simple as possible.
*/
template<class T>
class Stack {
public:
	/*! \fn A constructor
		\brief Create stack memory, assign size of the stack
	*/
	Stack(int stackSize) : stack(std::vector<T>(stackSize)), sizeStc(stackSize), addCount(0) {}

	/*! \fn push
		\brief Puts one object on the stack.

		When stack is overload, automatticaly add one more place.
		(Used vector abillity to adding new memory space in this case)
	*/
	void push(T data);

	/*! \fn push
		\brief Puts one object on the stack.

		When stack is overload, automatticaly add percent of old place as a added new memory.
		After hitting fullness, multiply size of the vector twice.
	*/
	void push_prc(T data);
	/*! \fn pop */
	T pop();

	/*!	\fn size */
	inline int size(){
		return this->sizeStc;
	}

	/*! \fn operator<< */
	friend std::ostream& operator<<(std::ostream& out, const Stack& stack){
		for (auto iterator : stack.stack){
			out << iterator << ' ';
		}
		return out;
	}
private:
	/*!	\var stackBox
		\brief Container for stack date.
	*/
	std::vector<T> stack;

	/*! \var sizeStc */
	int sizeStc;

	/*! \var addCount
		\brief Counter of elements added to the vector

		Used in push_prc, if addCount == size, dupcilate vector.
		Testing purpose.
	*/
	int addCount;
};
#endif