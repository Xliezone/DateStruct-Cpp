#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Read(vector<int> &preOrder, vector<int> &inOrder) {
    int N;
    cin >> N;
    stack<int> stack;
    int index;
    if (N) {
        for (int i = 0; i < 2 * N; i++) {
            string op;
            cin >> op;
            if (op == "Push") {
                cin >> index;
                preOrder.push_back(index);
                stack.push(index);
            }
            if (op == "Pop") {
                inOrder.push_back(stack.top());
                stack.pop();
            }
        }
    }
}

struct Node {
    int data;
    int left;
    int right;
};

typedef vector<Node> Tree;

void Build() {

}

int main() {
    vector<int> preOrder;
    vector<int> inOrder;
    Read(preOrder, inOrder);
    return 0;
}
