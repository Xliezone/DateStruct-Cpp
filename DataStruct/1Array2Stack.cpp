//use an array to make two stacks
#include <iostream>

using namespace std;
typedef int ElementType;

constexpr const ElementType MAXSIZE = 100;

typedef struct Node {
	ElementType Array[MAXSIZE];
	size_t Top1 = -1;
	size_t Top2 = MAXSIZE;
} *Stack;

/*
f = 0 mean from top1
f = 1 mean from top2
*/
typedef int Flag;

void create(Stack &ptr) {
	ptr = new Node;
}

void push(Stack &ptr, Flag f, ElementType data) {
	if (ptr->Top1 == ptr->Top2 - 1) {
		cout << "Error, the stack is full!" << endl;
	}
	else if (!f) {
		ptr->Top1++;
		ptr->Array[ptr->Top1] = data;
	}
	else if (f) {
		ptr->Top2--;
		ptr->Array[ptr->Top2] = data;
	}
}

ElementType pop(Stack &ptr, Flag f) {
	ElementType x;
	if (!f) {
		if (ptr->Top1 != -1) {
			x = ptr->Array[ptr->Top1];
			ptr->Top1--;
		}
		else {
			cout << "Error, the stack is empty" << endl;
			x = 0;
		}
	}
	else {
		if (ptr->Top2 != MAXSIZE) {
			x = ptr->Array[ptr->Top2];
			ptr->Top2++;
		}
		else {
			cout << "Error, the stack is empty" << endl;
			x = 0;
		}
	}
	return x;
}

void display(Stack &ptr, Flag f) {
	if (!f) {
		for (size_t i = 0; i <= ptr->Top1; i++) {
			cout << ptr->Array[i] << "\t";
		}
		cout << endl;
	}
	else {
		for (size_t i = MAXSIZE -1; i >= ptr->Top2; i--) {
			cout << ptr->Array[i] << "\t";
		}
		cout << endl;
	}
}

int main() {
	Stack ptr;
	create(ptr);
	for (size_t i = 0; i < 10; i++) {
		if (i % 2)
			push(ptr, 0, i);
		else
			push(ptr, 1, i);
	}
	display(ptr, 0);
	display(ptr, 1);
	for (size_t i = 0; i < 5; i++) {
		if (i % 2)
			pop(ptr, 0);
		else
			pop(ptr, 1);
	}
	display(ptr, 0);
	display(ptr, 1);
	system("pause");
}