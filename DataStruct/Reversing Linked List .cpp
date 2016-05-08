#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
	string post;
	int position;
	string after;
	Node* prior;
	Node* next;
}* List;

List Read();
void Append(string &post, int &position, string &after, List &Rear);
List Sort(List &head);
void Print(List &head);

int main() {
	List L;
	L = Read();
	L = Sort(L);
	Print(L);
	return 0;
}

List Read() {
	List Head;
	Head = (List) new List;
	Head->prior = NULL;
	Head->next = NULL;
	string hpost;
    int hposi;
    string hafter;
	cin >> hpost >> hposi >> hafter;
    Head->post = hpost;
    Head->position = hposi;
    Head->after = hafter;
	List Rear;
	Rear = Head;
	while (Head->position-- > 0) {
		string post;
		int position;
		string after;
		cin >> post >> position >> after;
		Append(post, position, after, Rear);
	}
	return Head;
}

void Append(string &post, int &position, string &after, List &Rear) {
	List node;
	node = (List) new List;
	node->post = post;
	node->position = position;
	node->after = after;
	node->next = NULL;
	Rear->next = node;
	node->prior = Rear;
	Rear = node;
}

List Sort(List &head) {
	List Rear, copyRear;
	Rear = head->next;
	List copy;
	copy = (List) new List;
	copy->prior = NULL;
	copy->post = head->post;
	copy->position = head->position;
	copy->after = head->after;
	copyRear = copy;
	for (int i = 1; i <= head->position; ++i) {
		for (int j = 1; j <= head->position; ++j) {
			if (i == Rear->position) {
				Append(Rear->post, Rear->position, Rear->after, copyRear);
				copyRear = copyRear->next;
				break;
			}
			else
				Rear = Rear->next;
		}
		Rear = head->next;
	}
	head = copy;
	copy = Rear;
	free(copy);
	copy = NULL;
	return head;
}

List Swap(List &head) {
	return head;
}

void Print(List &head) {
	List Rear = head;
	while (Rear) {
		cout << Rear->post << " " << Rear->position << " "
		     << Rear->after << endl;
		Rear = Rear->next;
	}
}
