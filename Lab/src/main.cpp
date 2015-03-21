/*! 
\file main.cpp
\brief A master file
*/

#include "tree.h"
#include "tree_node.h"
#include "queue.h"
#include "list.h"
#include "stack.h"
#include "inputfile_txt.h"
#include "benchmark_frm.h"


int main(int argc, char* argv[]){
	
	// contains only one size, implementation from Lab1
	std::vector<int>fileSize;
	// First argument is a name of the program so i = 1
	for (int i = 1; i < argc; i++)
		fileSize.push_back(atoi(argv[i]));
	
	InputFiles openFile(argc, fileSize);
	openFile.generate_random_int_data();

	Benchmark treeTest;
	Tree newTree(openFile,treeTest);

	Benchmark queueTest(treeTest);
	Queue newQueue(openFile, queueTest);

	Benchmark listTest(treeTest);
	List newList(openFile, listTest);

	Benchmark stackTest(treeTest);
	Stack newStack(openFile, stackTest);

	system("pause");
	return 0;
}