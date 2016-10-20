#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2*n-1; j++) {
			if (j <= n-i || j >= i+n)
				std::cout << ' ';
			else
				std::cout << '*';
		}
		std::cout << std::endl;
	}
	return 0;
}