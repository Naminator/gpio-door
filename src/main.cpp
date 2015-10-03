#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "Hello World." << endl;
	cout << "Hardware Concurrency: " << thread::hardware_concurrency() << endl;

	return 0;
}
