/*!	
\file stack.cpp
\brief A stack class source code.
*/
#include <stack.h>
template<class T>
void Stack<T>::push(T data){
	if (addCount < sizeStc)
		stack[addCount] = data;
	else
		stack.push_back(data);
	addCount++;
}

template<class T>
void Stack<T>::push_prc(T data){
	//duplicate memory
	if (addCount == sizeStc)
	{
		stack.resize(sizeStc * 2);
		sizeStc *= 2;
	}
	stack[addCount] = data;
	addCount++;
}

template<class T>
T Stack<T>::pop(){
	--addCount;
	assert(addCount >= 0 && "You're trying to pop element from empty vector.");
	T element = stack[addCount];
	stack.erase(stack.begin() + addCount);
	sizeStc--;
	return element;
}