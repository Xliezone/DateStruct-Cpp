#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool isPrime(int x)
{
    if (x == 1)
        return false;
    if (x == 2)
        return true;

    for (int i = 2; i <= sqrt((double)x); i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int M, N;
    cin >> M >> N;

    int count = 0;
    int row = 0;

    for (int i = 2;; i++)
    {
        if (isPrime(i))
        {
            count++;
            if (count >= M)
            {
                row++;
                if (row == 1)
                    printf("%d", i);
                else if (row != 10)
                    printf(" %d", i);
                else if (row == 10)
                {
                    printf(" %d\n", i);
                    row = 0;
                }
            }
        }
        if (count == N)
            break;
    }
}