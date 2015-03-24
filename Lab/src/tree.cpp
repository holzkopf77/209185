/*! 
	\file tree.cpp
	\brief A source file for Tree class.
*/
#include "tree.h"

template<class T>
void Tree<T>::show_tree(){
	//TODO: THIS FN IS NOT WORKING
	auto rootL = root;
	auto rootR = root;
	//root 1lvl
	std::cout << "root: " << root->get_data() << std::endl;

	//2lvl
	while (rootL->return_left() != nullptr || rootR->return_right() != nullptr){
		std::cout << rootL->return_left()->get_data() << "\t";
		rootL = rootL->return_left();
		std::cout << rootR->return_right()->get_data() << "\t" << std::endl;
		rootR = rootR->return_right();
	}
}

template<class T>
void Tree<T>::push(T data){
	if (sizeTre == 0){
		root->data = data;
		root->empty = false;
		sizeTre++;
		empty = false;
	}
	else{
		while (1){
			if (root->get_data() >= data){
				// find free left branch pointer
				if (root->return_left() != nullptr){
					root = root->return_left();
					continue;
				}
				root->left = new NodeB<T>(data);
				root->left->parent = root;
				sizeTre++;
				break;
			}
			else{
				// find free right branch pointer
				if (root->return_right() != nullptr){
					root = root->return_right();
					continue;
				}
				root->right = new NodeB<T>(data);
				root->right->parent = root;
				sizeTre++;
				break;
			}
		}
		//come back with root pointer
		while (root->return_parent() != nullptr)
			root = root->return_parent();
	}
}

template<class T>
T Tree<T>::pop(T data){
	T retData = 0;
	NodeB<T>* deletedPtr;
	assert(sizeTre > 0 && "You're trying to delete empty root node");
	if (sizeTre == 1){
		retData = root->get_data();
		root->data = 0;
		sizeTre--;
		return retData;
	}
	else{
		sizeTre--;
		//find our node with data
		while (root->get_data() != data){
			if (root->get_data() > data){
				root = root->return_left();
			}
			else{
				root = root->return_right();
			}
		}
		//check if this node has child
		//case 1 - NO CHILD -
		if (root->return_left() == nullptr && root->return_right() == nullptr){
			retData = root->get_data();
			deletedPtr = root;
			if (root->parent->get_data() >= data)
				root->parent->left = nullptr;
			else
				root->parent->right = nullptr;

			while (root->return_parent() != nullptr)
				root = root->return_parent();
			
			deletedPtr->~NodeB();
			deletedPtr = nullptr;
			return retData;
		}

		//case 2 - ONE CHILD -
		if (root->return_left() != nullptr || root->return_right() == nullptr){
			retData = root->get_data();
			deletedPtr = root;

			root->parent->left = root->left;

			while (root->return_parent() != nullptr)
				root = root->return_parent();
			deletedPtr->left = nullptr;
			deletedPtr = nullptr;
			return retData;
		}

		if (root->return_left() == nullptr || root->return_right() != nullptr){
			retData = root->get_data();
			deletedPtr = root;

			root->parent->left = root->right;

			while (root->return_parent() != nullptr)
				root = root->return_parent();
			deletedPtr->right = nullptr;
			deletedPtr = nullptr;
			return retData;
		}
	}
	return retData;
}