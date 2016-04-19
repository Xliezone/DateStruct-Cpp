#include <iostream>

using namespace std;

typedef struct Node {
	int post;
	int posi;
	int after;
	Node * next;
}* List;

List Read();

int main() {
	List L;
	L = Read();
	I = Sort(L);
	S = Swap(I);
	Print(S);
	return 0;
}

List Read() {
	List L, Rear;
	L = (List) new List;
	L->next = NULL;
	cin >> L->post >> L->posi >> L->after;
	int n = L->posi;
}

void Append(int &post, int ) {
}