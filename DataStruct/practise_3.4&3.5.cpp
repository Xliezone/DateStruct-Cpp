//practise_3.4&3.5
#include <iostream>
#include <vector>

using namespace std;

vector<int> Vand(int a[], int *enda, int b[], int *endb) {
    vector<int> v;
    while (a != enda && b != endb) {
        if (*a < *b)
            a++;
        else if (*a == *b) {
            v.push_back(*a);
            a++;
            b++;
        }
        else if (*a > *b)
            b++;
    }
    return v;
}

vector<int> Vmerge(int a[], int *enda, int b[], int *endb) {
    vector<int> v;
    while (a != enda && b != endb) {
        if (*a < *b) {
            v.push_back(*a);
            a++;
        }
        else if (*a == *b) {
            v.push_back(*a);
            a++;
            b++;
        }
        else if (*a > *b) {
            v.push_back(*b);
            b++;
        }
    }
    while (a != enda) {
        v.push_back(*a);
        a++;
    }
    while (b != endb) {
        v.push_back(*b);
        b++;
    }
    return v;
}

int main(int argc, char const *argv[]) {
    int a1[] = {0, 1, 2, 3, 4, 5, 6};
    int a2[] = {1, 3, 5, 6, 9};
    vector<int> v1 = Vand(a1, end(a1), a2, end(a2));
    vector<int> v2 = Vmerge(a1, end(a1), a2, end(a2));
    return 0;
}