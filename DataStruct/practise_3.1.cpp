//parctise 3.1
#include <iostream>
#include <vector>

using namespace std;

void PrintLots(vector<int> &a, vector<int> &b) {
	for (int i = 0; i < b.size(); ++i)
	{
		cout << a[b[i]] << endl;
	}
}

int main(int argc, char const *argv[])
{
	std::vector<int> a = {0, 1, 2, 3 ,4 ,5 ,6};
	std::vector<int> b = {0, 2, 5};
	PrintLots(a, b);
	return 0;
}