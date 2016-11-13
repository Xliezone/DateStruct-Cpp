#include <iostream>

#define MAXSIZE 100

using namespace std;

typedef int ElementType;

typedef struct Node {
    ElementType Array[MAXSIZE];
    size_t top;
} *Stack;

void create(Stack &ptrS) {
    ptrS = new Node;
    ptrS->top = 0;
}

void push(Stack &ptrs, ElementType data) {
    if (ptrs->top < MAXSIZE - 1) {
        ptrs->top++;
        ptrs->Array[ptrs->top] = data;
    } else {
        cout << "\nError, out of range" << endl;
    }
}

ElementType pop(Stack &ptrs) {
    ElementType x;
    if (ptrs->top > 0) {
        x = ptrs->Array[ptrs->top];
        ptrs->Array[ptrs->top] = 0;
        ptrs->top--;
    } else {
        ptrs->Array[ptrs->top] = x = 0;
        ptrs->top = 0;
        cout << "Stack is empty!" << endl;
    }
    return x;
}

void display(Stack &ptrs) {
    cout << "Top is :" << ptrs->Array[ptrs->top] << endl;
}

int main() {
    Stack p;
    create(p);
    for (int i = 0; i < 10; ++i) {
        push(p, i);
        display(p);
    }
    for (int j = 0; j < 5; ++j) {
        pop(p);
        display(p);
    }
    system("pause");
    return 0;
}