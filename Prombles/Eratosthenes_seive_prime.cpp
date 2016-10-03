#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[])
{
	const int n = 1000;
	int array[n+1];
	for (int i = 0; i < n + 1; i++)
		array[i] = i;
	int count = 0;
	int i = 2;
	while (i < n+1) {
		std::cout << setw(5) << array[i];
		count++;
		if (count%10 == 0)
			std::cout << std::endl;
		for (int j = i; j < n+1; j += i) 
			array[j] = 1;
		while (array[i] == 1)
			i++;
	}
	return 0;
}