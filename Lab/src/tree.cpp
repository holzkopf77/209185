/*! 
\file tree.cpp
\brief A source file for Tree class.
*/
#include "tree.h"

// constructor
Tree::Tree(InputFiles& file, Benchmark& treeTest){
	/*! \todo memory problems, maybe new deconstructor? */
	
	// open file for data in root
	std::fstream openFile;
	// container for first data
	int rootData;
	// take name of this file
	std::string fileName;
	// file size
	int fileSize;
	// average time from test
	long double avrgTime;

	for (int i = 0; i < file.return_number_files() - FIRST_ARGUMENT; i++){
		fileName = file.return_file_name(i);
		fileSize = file.return_file_size(i);
		for (int i = 0; i < 10; i++){
			openFile.open(fileName + ".txt");
			// Check if file is opened correctly
			assert(openFile.is_open() && "I can't open this file.");

			// create root node, put there first value from file
			openFile >> rootData;
			root = new Node(rootData);

			//start test here
			treeTest.test(openFile, root);

			//initial again for next test
			root->~Node();
			root = NULL;
			rootData = 0;
			openFile.close();
		}
		avrgTime = treeTest.getAvr(treeTest.testTimes);
		treeTest.generateRaport(avrgTime, fileSize, fileName, BIN_TREE);
	}
}

	
// deconstructor
Tree::~Tree(){
	delete root;
}

void Tree::show_tree()
{
	//root 1lvl
	std::cout << "root: " << root->get_data_container() << std::endl;
	//2lvl
	if (root->return_left() != NULL)
		std::cout << "root(L): " << root->return_left()->get_data_container() << "\t";
	if (root->return_right() != NULL)
		std::cout << "root(R): " << root->return_right()->get_data_container() << std::endl;
	//3lvl
	if (root->return_left()->return_left() != NULL)
		std::cout << "root(LL2): " << root->return_left()->return_left()->get_data_container() << "\t";
	if (root->return_left()->return_right() != NULL)
		std::cout << "root(LR2): " << root->return_left()->return_right()->get_data_container() << "\t";
	if (root->return_right()->return_left() != NULL)
		std::cout << "root(RL2): " << root->return_right()->return_left()->get_data_container() << "\t";
	if (root->return_right()->return_right() != NULL)
		std::cout << "root(RR2): " << root->return_right()->return_right()->get_data_container() << std::endl;

}