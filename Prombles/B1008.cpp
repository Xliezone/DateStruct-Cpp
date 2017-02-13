#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int array[N];
    for (auto &v : array) {
        cin >> v;
    }

    int real = M % N;
    if (real == 0)
        real = 0;
    else
        real = N - real;
    int count = 0;

    for (int i = real; i < N; ++i) {
        if(!count++)
            cout << array[i];
        else
            cout << " " << array[i];
    }
    if (real != 0)
    for (int j = 0; j < real; ++j) {
        cout << " " << array[j];
    }

}