#include <iostream>

using namespace std;

//make a stack with linked list

typedef int ElementType;

typedef struct Node {
	ElementType data;
	Node *next;
} *Stack;

Stack create() {
	Stack sh = new Node;
	sh->data = -1;
	sh->next = nullptr;
	return sh;
}

inline bool isEmpty(Stack &sh) {
	return (sh->next == nullptr);
}


void push(Stack &s, ElementType data) {
	Stack now = new Node;
	now->data = data;
	now->next = s;
	s = now;
}

ElementType pop(Stack &s) {
	if (isEmpty(s)) {
		cout << "Error, the stack is empty" << endl;
		return NULL;
	}
	ElementType x = s->data;
	Stack temp = s;
	s = s->next;
	delete temp;
	temp = nullptr;
	return x;
}


int main() {
	Stack s = create();
	for (size_t i = 0; i < 10; i++) {
		push(s, i);
	}
	pop(s);
	ElementType x = pop(s);
	cout << x << endl;
	system("pause");
	return 0;
}