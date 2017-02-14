#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long a, b , c;
    int n;
    cin >> n;
    int i = 1;
    while (i++ <= n) {
        cin >> a >> b >> c;
        printf("Case #%d: ", i - 1);
        cout << (a + b > c ? "true" : "false") << endl;
    }
}