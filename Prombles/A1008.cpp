#include <iostream>

using namespace std;

int main()
{
    int n;
    int now = 0;
    int sum = 0;

    cin >> n;

    while (cin >> n)
    {
        if (n > now)
        {
            sum += (n - now) * 6;
        }
        else
        {
            sum += (now - n) * 4;
        }
        sum += 5;
        now = n;
    }

    cout << sum;
}