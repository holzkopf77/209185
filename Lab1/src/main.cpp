#include "inputfile_txt.h"

int main(int argc, char* argv[])
{
	std::vector<int>Sizes;
	Sizes.push_back(10);
	Sizes.push_back(2);
	Sizes.push_back(3);
	Sizes.push_back(4);
	Sizes.push_back(41);

	InputFiles newFilesList(5, Sizes);
	newFilesList.show_info();
}