#include <iostream>

int main(int argc, char const *argv[])
{
    int k;
    std::cin >> k;
    int array[k];
    for (int i = 0; i < k; ++i)
    {
        std::cin >> array[i];
    }
    int sum = 0;
    int maxSum = array[0];
    int start = array[0];
    int temp = start;
    int stop = array[k - 1];
    for (int i = 0; i < k; ++i)
    {
        sum += array[i];
        if (sum > maxSum) {
            maxSum = sum;
            start = temp;
            stop = array[i];
        }
        if (sum < 0) {
            sum = 0;
            if (i < k - 1) {
                temp = array[i + 1];
            }
        }
    }
    if (maxSum < 0) {
        std::cout << 0 << " " << array[0] << " " << array[k - 1] << std::endl;
    }
    else
        std::cout << maxSum << " " << start << " " << stop << std::endl;
    return 0;
}