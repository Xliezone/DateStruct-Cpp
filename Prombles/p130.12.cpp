#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int i) {
	for (int n = 2; n <= sqrt(i); n++){
		if (i%n == 0)
			return false;
	}
	return true;
}
void fn(int i, int n) {

	int count = 0;
	while(count < n){
		if (isPrime(i)) {
			count++;
			cout << i << " ";
		}
		i++;
	}
}
int main(int argc, char const *argv[])
{
	int i, n;
	cin >> i >> n;


	fn (i, n);
	return 0;
}