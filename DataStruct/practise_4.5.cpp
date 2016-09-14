#include <iostream>

using namespace std;

void swapuser(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
int main(int arg, char const *argv){
    int a = 1,b = 2;
    swapuser(&a, &b);
    cout << a << endl << b << endl;
    return 0;
}