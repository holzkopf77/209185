/*!	
	\file queue.spp
	\brief A source code for Queue class
*/

#include "queue.h"

//Please don't ask me how it works, spent 3 hours to make it so.
//I've tested it with debugger from every side, it's unbreakable.
template<class T>
void Queue<T>::push(T data){
	if (sizeQue == 0){
		queue.push_back(data);
		sizeQue++;
		addCount++;
		tail++;
	}
	else{
		if (addCount < sizeQue){
			if ((head != 0) && (addCount < sizeQue)){
				if (head >= addCount){
					queue[addCount - 1] = data;
					addCount++;
				}
				else{
					queue[addCount - head - 1] = data;
					addCount++;
				}
			}
			else if ((head == 0) && (addCount <= sizeQue)){
				queue[addCount] = data;
				addCount++;
			}
		}
		else{
			if (head == 0){
				queue.push_back(data);
				sizeQue++;
				addCount++;
			}
			else{
				auto it = queue.begin();
				queue.insert(it + head, data);
				addCount++;
				head++;
				sizeQue++;
			}
		}
	}
}

template<class T>
T Queue<T>::pop(){
	assert(addCount > 0 && "You're trying to pop element from empty queue");
	addCount--;
	T element = queue[head];
	queue[head] = 0;
	head = (head + 1) % sizeQue;
	if (addCount == 0)
		head = 0;
	return element;
}