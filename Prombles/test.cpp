#include <iostream>
using namespace std;

struct Y
{
	int x;
};

Y* make() {
	Y *a = new Y;
	a->x = 1;
	return a;
}

int main(int argc, char const *argv[])
{
	auto x = make();
	cout << x->x << endl;
	return 0;
}