//practise_3.3
#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator cfind(vector<int>::iterator start, vector<int>::iterator end, int v)
{
    vector<int>::iterator it = start;
    while (it != end && *it != v) {
        it++;
    }
    return it;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7};
    auto a = cfind(arr.begin(), arr.end(), 3);
    auto b = cfind(arr.begin(), arr.end(), 10);
    cout << *a << endl;
    cout << *b << endl;
    return 0;
}
