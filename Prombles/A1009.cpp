#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    double p[1001] = {0.0};
    for (int i = 0; i < n; i++)
    {
        int x;
        double a;
        cin >> x >> a;
        p[x] = a;
    }
    cin >> n;
    double answer[2001] = {0.0};
    for (int j = 0; j < n; j++)
    {
        int x;
        double a;
        cin >> x >> a;
        for (int i = 0; i < 1001; i++)
        {
            answer[i + x] += p[i] * a;
        }
    }

    int cnt = 0;
    for (int i = 0; i < 2001; i++)
    {
        if (answer[i] != 0.0) cnt++;
    }

    cout << cnt;

    for (int i = 2000; i >= 0; i--)
    {
        if (answer[i] != 0.0)
            printf(" %d %.1f", i, answer[i]);
    }
}