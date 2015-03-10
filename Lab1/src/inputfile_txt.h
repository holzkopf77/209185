/*! \brief A new file object class header */
#ifndef inputfile_txt
#define inputfile_txt

#include <iostream>
#include <string>
#include <fstream>

class inputfile {	
	public:
		inputfile();
	private:
		int FilesNumber;
		std::string FilesNamesTab;
};
#endif