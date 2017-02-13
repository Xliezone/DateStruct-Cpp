#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*素数的判断方法
 * 首先判断n是否小于等于3 返回是否大于1
 * 2～sqrt（n）//cmath头文件
 * */
bool isPrime(int n){
    if (n <= 3)
        return n > 1;
    else {
        for (int i = 2; i <= sqrt(static_cast<double>(n)); ++i) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}

void prime(int n, vector<int> &primes){
    //make an array
    int array[n+1];
    for (int i = 0; i < n + 1; i++) {
        array[i] = i;
    }

    int k = 1;
    while (k <= n) {
        while (array[k] == 1)
            k++;
        if (isPrime(k)) {
            primes.push_back(k);
        }
        for (int j = k; j < n+1; j += k) {
            array[j] = 1;
        }
    }
}

int main(){
    int N;
    cin >> N;
    int count = 0;

    if (N > 3) {
        for (int i = 3; i <= N; ++i) {
            if (isPrime(i) && isPrime(i-2)) {
                count++;
                cout << i << " ";
            }
        }
    }
    cout << count;
}