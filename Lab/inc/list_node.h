/*!	
	\file list_node.h
	\brief Nodes for the list
*/
#ifndef lIST_NODE_H_
#define LIST_NODE_H_

/*! \class LNode
t
	An implementation for nodes to the linked list
*/
template<class T>
class Node{
public:

	/*! \fn A default constructor
	*/
	Node() : nodeData(T(0)), nextNode(nullptr) {}

	/*! \fn A constructor
	*/
	Node(T data) : nodeData(T(data)), nextNode(nullptr) {}
	
	/*! \fn ~Node()
		\brief A destructor
	*/
	~Node(){
			delete nextNode;
			nextNode = nullptr;
	}

	/*! \fn get_data
		\brief return data from selected node
	*/
	const T get_data() const{
		return nodeData;
	}

	/*! \fn get_data
		\brief return pointer to the next node.
	*/
	const Node<T>* get_nextNode() const{
		return nextNode;
	}

	//access to private part
	template<class T>
	friend class List;

private:
	/*! \var nodeData
		Container for data inside node.
	*/
	T nodeData;

	/*! \var nextNode
		Pointer to the next node in linked list.
	*/
	Node<T>* nextNode;
};
#endif