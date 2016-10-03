// input:2038
// output:2038+8302=10340

#include <iostream>
#include <cmath>

using namespace std;

int res(int n, int bit) {
	if(n >= 10) {
		int m = n % 10;
		return m * static_cast<int>(pow(10, bit)) + res(n/10, --bit);
	}
	else
		return n;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int m = n;
	int i = 0;
	while(m >= 10) {
		i++;
		m /= 10;
	}
	cout << n + res(n, i) << endl;
	return 0;
}
