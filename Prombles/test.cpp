#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum(const int a, const int b){
	return a + b;
}

int main(){
	int (*p)(const int , const int) = sum;
	cout << p(1, 2) << endl;
	return 0;
}