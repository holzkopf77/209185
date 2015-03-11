#include "inputfile_txt.h"
#include "benchmark_frm.h"

int main(int argc, char* argv[])
{
	//! Container for sizes from command prompt
	std::vector<int>FilesSizes;

	//! First argument is a name of the program so i = 1
	for (int i = 1; i < argc ; i++)
		FilesSizes.push_back(atoi(argv[i]));
	
	InputFiles newFilesList(argc, FilesSizes);
	Benchmark NewTest;
	newFilesList.generate_random_int_data();
	NewTest.test(newFilesList);
}