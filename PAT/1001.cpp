#include <iostream>

int main(int argc, char const *argv[]) {
    int n;
    std::cin >> n;
    int i = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else
            n = (3 * n + 1) / 2;
        i++;
    }
    std::cout << i << std::endl;
    return 0;
}
