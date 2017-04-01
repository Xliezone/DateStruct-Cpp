#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;

    int sum = -1;
    bool allNegative = true;
    vector<int> v(N);

    for (auto i = 0; i < N; i++){
        cin >> v[i];
        if (v[i] >= 0) allNegative = false;

    }

    int left = 0;
    int temp_sum = 0;
    int temp_left = 0;
    int temp_right = 0;
    for (auto i = 0; i < v.size(); i++){
        temp_sum += v[i];
        if (temp_sum > sum) {
            sum = temp_sum;
            left = temp_left;
            temp_right = i;
        }
        else if (temp_sum < 0){
            temp_sum = 0;
            temp_left = i + 1;
        }

    }

    if (allNegative){
        printf("0 %d %d", v[0], v[N-1]);
    } else {
        printf("%d %d %d", sum, v[left], v[temp_right]);
    }
}