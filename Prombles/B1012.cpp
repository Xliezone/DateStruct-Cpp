#include <iostream>
#include <vector>

#define FIN -10000000;

using namespace std;

void a1(vector<int> &arr);

void a2(vector<int> &arr);

void a3(vector<int> &arr);

void a4(vector<int> &arr);

void a5(vector<int> &arr);

int main() {
    int N;
    cin >> N;
    auto n = N;
    vector<int> arr;
    while (n-- != 0) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    a1(arr);
    a2(arr);
    a3(arr);
    a4(arr);
    a5(arr);
}

void a1(vector<int> &arr) {
    int y = 0;
    int cnt = 0;
    for (auto v : arr) {
        if (v % 10 == 0) {
            cnt++;
            y += v;
        }
    }
    if (cnt)
        printf("%d ", y);
    else
        printf("N ");
}

void a2(vector<int> &arr) {
    int y = 0;
    int cnt = 0;
    for (auto v : arr) {
        if (v % 5 == 1) {
            cnt++;
            if (cnt % 2 != 0)
                y += v;
            else
                y -= v;
        }
    }
    if (cnt)
        printf("%d ", y);
    else
        printf("N ");
}

void a3(vector<int> &arr) {
    int y = 0;
    int cnt = 0;
    for (auto v : arr) {
            if (v % 5 == 2) {
            cnt++;
        }
    }
    if (cnt)
        printf("%d ", cnt);
    else
        printf("N ");
}

void a4(vector<int> &arr) {
    double y = 0;
    int cnt = 0;
    for (auto v : arr) {
        if (v % 5 == 3) {
            cnt++;
            y += v;
        }
    }
    if (cnt) {
        printf("%.1f ", y/cnt);
    } else {
        printf("N ");
    }
}

void a5(vector<int> &arr) {
    int y = 0;
    int cnt = 0;
    for (auto v : arr) {
        if (v % 5 == 4 && v > y) {
            y = v;
            cnt++;
        }
    }
    if (cnt)
        printf("%d", y);
    else
        printf("N");
}
