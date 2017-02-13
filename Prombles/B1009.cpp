#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> lan;
    string word;
    while (cin >> word) {
        lan.push_back(word);
    }

    int i = 0;
    for (auto it = lan.crbegin(); it != lan.crend(); it++) {
        if (!i++)
        cout << *it;
        else
            cout << " " << *it;
    }
}
