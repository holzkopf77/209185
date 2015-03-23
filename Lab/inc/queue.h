/*!	
	\file queue.h
	\brief Own implementation of queue.
*/
#ifndef QUEUE_H_
#define QUEUE_H_

#include <vector>
#include <cassert>

/*! \class Queue

	An implementation of queue based on dynamically created table. 
	Info based on http://www.studytonight.com/data-structures/queue-data-structure
*/
template<class T>
class Queue {
public:
	/*! \fn A default constructor
		\brief Creates an empty queue.
	*/
	Queue() : queue(std::vector<T>(0)), head(0), tail(0), sizeQue(0), addCount(0) {}

	/*! \fn A constructor with fixed size of the queue

		\param queueSize fixed size of the queue;
	*/
	Queue(int queueSize) : queue(std::vector<T>(queueSize)), head(0), tail(0), sizeQue(queueSize), addCount(0) {}

	/*! \fn push
		\brief add new data to the queue
		
		When queue is full + all filled -> add new place at the end
		When queue is full + some free space -> put at first free space new element
		When queue is not full -> put at first free space new element
		When queue is empty, and you want to pop something -> assert is on
		When queue is fill, and you want to pop -> pop very first element.
		Just like normal queue.
	*/
	void push(T data);

	/*! \fn pop
	*/
	T pop();


	/*! \fn size
		\brief return size of the queue
	*/
	const inline int size(){
		return sizeQue;
	}

	/*! \fn operator<<
		\brief Overloaded operator << for displaying the queue
	*/
	friend std::ostream& operator<<(std::ostream& out, const Queue& queue){
		for (auto iterator : queue.queue){
			out << iterator << ' ';
		}
		return out;
	}
private:
	/*! \var queueTab
		A dynamic container for elements of queue (vector)
	*/
	std::vector<T> queue;

	/*! \var head
		Last element from the queue
	*/
	int head;

	/*! \var tail
		A free place inside the queue
	*/	
	int tail;

	/*! \var sizeQue
	*/
	int sizeQue;

	/*! \var addCount
	\brief Counter of elements added to the vector

	Testing purpose.
	*/
	int addCount;
};
#endif