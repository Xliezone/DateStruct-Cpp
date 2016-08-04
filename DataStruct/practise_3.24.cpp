//use an array to make two stacks
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
    int length;
    int stack[length];
    size_t top1 = 0;
    size_t top2 = length-1;
    //push
    int number;
    stack[top1] = number;
    top1++;
    stack[top2] = number;
    top2--;
    //pop
    stack[top1] = 0;
    top1--;
    stack[top2] = 0;
    top2++;
    //get
    // stack[top1] || stack[top2]
    return 0;
}