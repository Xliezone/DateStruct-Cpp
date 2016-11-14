#include <iostream>

using namespace std;

//make a queue with linked list

typedef int ElementType;

struct Node {
	ElementType data;
	Node *next;
};

typedef struct Q {
	Node *front;
	Node *rear;
} *Queue;

Queue create() {
	Queue q = new Q;
	q->front = new Node;
	q->front->data = -1;
	q->front->next = nullptr;
	q->rear = q->front;
	return q;
}

bool isEmpty(Queue &q) {
	if (q->front == q->rear) {
		return true;
	}
	return false;
}

void push(Queue &q, ElementType data) {
	Node *temp = new Node;
	temp->data = data;
	temp->next = nullptr;
	q->rear = q->rear->next = temp;
}

ElementType pop(Queue &q) {
	if (isEmpty(q)) {
		cout << "Error, the queue is empty" << endl;
		return NULL;
	}
	Node *temp = q->front->next;
	ElementType td = temp->data;
	q->front->next = temp->next;
	delete temp;
	temp = nullptr;
	return td;
}

int main() {
	Queue q = create();
	for (size_t i = 0; i < 10; i++) {
		push(q, i);
	}
	pop(q);
	pop(q);
	ElementType x = pop(q);
	cout << x << endl;
}