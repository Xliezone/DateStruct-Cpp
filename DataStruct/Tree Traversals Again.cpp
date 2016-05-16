#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> preOrder;
vector<int> inOrder;

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

typedef struct TNode {
    int data;
    TNode *left, *right;
} *Node;

void buildTree1(Node &T, int PreIndex, int InIndex, int len) {
    if (len <= 0) {
        T = 0;
        return;
    }
    T = (Node) malloc(sizeof(TNode));
    //存节点
    T->data = preOrder[PreIndex];
    //找出节点在中序序列中的位置
    int p;
    for (int i = 0; i < inOrder.size(); ++i) {
        if (inOrder[i] == preOrder[PreIndex]) {
            p = i;
        }
    }
    //左子树的长度
    int LenF = p - InIndex;
    //建立左子树
    buildTree1(T->left, PreIndex + 1, InIndex, LenF);
    //右子树的长度
    int LenR = len - 1 - LenF;
    //建立右子树
    buildTree1(T->right, PreIndex + LenF + 1, p + 1, LenR);
}

void Print(Node &tree, int count) {
    if (tree != 0) {
        Print(tree->left, 1);
        Print(tree->right, 1);
        if (count == 0)
            cout << tree->data;
        else
            cout << tree->data << " ";
    }
}

int main() {
    Read(preOrder, inOrder);
    Node root;
    buildTree1(root, 0, 0, preOrder.size());
    Print(root, 0);
    return 0;
}