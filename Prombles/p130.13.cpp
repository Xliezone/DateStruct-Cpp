#include <iostream>

int main(int argc, char const *argv[])
{
	for (int i = 1; i < 10; i++){
		for (int j = 0; j < 10; j++) {
			if (i*2+j >= 10 && i*100+j*10+i > 100 && i*100+j*10+i < 500)
				std::cout << i*100+j*10+i << ' ';
		}
	}
	return 0;
}