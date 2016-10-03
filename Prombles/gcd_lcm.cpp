//欧几里得算法求最大公约数，最小公倍数
#include <iostream>

using namespace std;

int gcd(int m, int n) {
	if (m % n == 0)
		return n;
	else
		return gcd(n, m % n);
}

int lcm(int m, int n) {
	return m * n / gcd(m,n);
}

int main()
{
	int m,n;
	cin >> m >> n;
	cout << gcd(m, n) << endl << lcm(m, n) << endl;
}