/*! 
	\file main.cpp
	\brief A master file
*/
#include <iostream>

#include "benchmark_frm.h"
#include "inputfile_txt.h"
#include "stack.h"
#include "list.h"
#include "queue.h"
#include "tree.h"

#include "benchmark_frm.cpp"
#include "list.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "tree.cpp"

int main(int argc, char* argv[]){

	/************file management***********/
	// contains only one size, implementation from Lab1
	std::vector<int>fileSize;
	// first argument is a name of the program so i = 1
	for (int i = 1; i < argc; i++)
		fileSize.push_back(atoi(argv[i]));
	
	InputFiles openFile(argc, fileSize);
	openFile.generate_random_int_data();
	/************file management***********/


	Benchmark<Tree<int>> treeTest;
	Benchmark<Stack<int>> stackTest;
	Benchmark<Queue<int>> queueTest;
	Benchmark<List<int>> listTest;

	List<int> list;
	Stack<int> stack;
	Tree<int> tree;
	Queue<int> queue;

	stackTest.test(stack, openFile);
	treeTest.test(tree, openFile);
	queueTest.test(queue, openFile);
	listTest.test(list, openFile);

	std::cin.get();
	return 0;
}