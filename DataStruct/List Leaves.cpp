#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int left;
    int right;
};

struct Leave {
    int posi;
    int floor;
};

typedef vector<Node> Tree;
typedef vector<Leave> Leaves;

int Read(Tree &tree) {
    int N;
    cin >> N;
    int root = -1;
    if (N) {
        int i = 0;
        int check[N];// 0 is root
        for (i = 0; i < N; i++) {
            check[i] = 0;
        }
        for (i = 0; i < N; i++) {
            Node elem;
            char cl;
            char cr;
            cin >> cl >> cr;
            if (cl != '-') {
                elem.left = cl - '0';
                check[elem.left] = 1;
            }
            else
                elem.left = -1;
            if (cr != '-') {
                elem.right = cr - '0';
                check[elem.right] = 1;
            }
            else
                elem.right = -1;
            tree.push_back(elem);
        }
        for (i = 0; i < N; i++) {
            if (check[i] == 0)
                root = i;
        }
    }
    return root;
}

Leaves L;

void getLeave(int root, Tree tree, int floor = -1) {
    if (root > -1) {
        floor++;
        if (tree[root].left == -1 && tree[root].right == -1) {
            Leave elem;
            elem.posi = root;
            elem.floor = floor;
            L.push_back(elem);
        }
        else {
            getLeave(tree[root].left, tree, floor);
            getLeave(tree[root].right, tree, floor);
        }
    }
}

int main() {
    /* TODO
     * read and build tree
     * get the floor
     * get leaves
     * sort and print*/
    Tree tree;
    int root = Read(tree);
    getLeave(root, tree);
    int flag = 0;
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < L.size(); ++i) {
            if (j == L[i].floor && flag == 0) {
                cout << L[i].posi;
                flag++;
            }
            else if (j == L[i].floor)
                cout << " " << L[i].posi;
        }
    }
}