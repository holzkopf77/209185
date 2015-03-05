#include <iostream>
#include <ctime>
#include <random>
#include <boost\timer\timer.hpp>

int main(int argc, char* argv[])
{
	using std::cout;
	using std::endl;
	using std::cin;
	using std::mt19937;
	using std::uniform_int_distribution;

	int* intTable = new int[argc];
	int seedGen = time(NULL);
	int Counter = 0;
	mt19937 randomNumbr(seedGen);
	uniform_int_distribution<>range(0, argc);

	//Start measure time
	boost::timer::auto_cpu_timer t;
	for (Counter; Counter < argc; Counter++)
	{
		intTable[Counter] = range(randomNumbr);
	}
	cin.get();

}