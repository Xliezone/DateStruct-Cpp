#include <iostream>

int main(int argc, char const *argv[])
{
	int k1;
	std::cin >> k1;
	int v1[k1][2];
	int *p = v1[0];
	for (int i = 0; i < k1 * 2; i++) {
		std::cin >> *(p + i);
	}
	int k2;
	std::cin >> k2;
	int v2[k2][2];
	p = v2[0];
	for (int i = 0; i < k2 * 2; i++) {
		std::cin >> *(p + i);
	}
	// *
	std::vector<int> answer1;
	int av1[2];
	for (int i = 0; i < k1; i++) {
		for (int j = 0; j < k2; j++) {
			av1 = {v1[i][0] * v2[j][0], v1[i][1] + v2[j][1]};
			answer1.push_back(av1);
		}
	}
	return 0;
}