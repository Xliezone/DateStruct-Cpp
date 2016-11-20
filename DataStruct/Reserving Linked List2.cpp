#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

struct Node {
	string Address;
	int Data;
	string Next;
};

typedef vector<Node> Array;

int main() {
	string head;
	int num, renum;
	cin >> head >> num >> renum;
	Array arr;
	while (num-- != 0) {
		Node temp;
		cin >> temp.Address >> temp.Data >> temp.Next;
		arr.push_back(temp);
	}
	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = i; j < arr.size(); j++) {
			if (arr[i].Data > arr[j].Data) {
				Node t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
	Array stack;
	Array right;
	int count = 0;
	for (size_t i = 0; i < arr.size(); i++) {
		stack.push_back(arr[i]);
		count++;
		if (count == renum) {
			while (count != 0) {
				right.push_back(stack.back());
				stack.pop_back();
				count--;
			}
		}
	}
	for (auto i : stack) {
		right.push_back(i);
	}
	for (size_t i = 0; i < right.size(); i++) {
		if (i != right.size()-1) {
			right[i].Next = right[i + 1].Address;
		}
		else {
			right[i].Next = "-1";
		}
		cout << right[i].Address << " " << right[i].Data << " " << right[i].Next << endl;
	}
	return 0;
}