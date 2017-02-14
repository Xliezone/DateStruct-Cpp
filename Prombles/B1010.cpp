#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a, n;
    int flag = 0;
    while (cin >> a >> n) {
        if (n) {
            if (flag++)
                cout << " ";
            cout << a*n << " " << n-1;
        }
    }
    if (flag == 0)
        cout << "0 0" <<endl;
}