#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char data;
    int left;
    int right;
};

typedef vector<Node> tree;

tree t1;
tree t2;

int Read(tree &t) {
    int N;
    cin >> N;
    int i = 0;
    int root = -1;
    if (N) {
        int check[N];
        for (int j = 0; j < N; j++) {
            check[j] = 0;
        }
        for (i = 0; i < N; ++i) {
            Node elem;
            char cl;
            char cr;
            cin >> elem.data >> cl >> cr;
            if (cl != '-') {
                elem.left = cl - '0';
                check[elem.left] = 1;
            }
            else {
                elem.left = -1;
            }

            if (cr != '-') {
                elem.right = cr - '0';
                check[elem.right] = 1;
            }
            else {
                elem.right = -1;
            }
            t.push_back(elem);
        }
        for (i = 0; i < N; i++) {
            if (check[i] == 0) {
                root = i;
                break;
            }
        }
    }
    return root;
}

bool Compare(int root1, int root2) {
    if (root1 == -1 && root2 == -1)
        return true;
    if ((root1 == -1 && root2 != -1) || (root1 != -1 && root2 == -1))
        return false;
    if (t1[root1].data != t2[root2].data)
        return false;
    if (t1[root1].left == -1 && t2[root2].left == -1)
        return Compare(t1[root1].right, t2[root2].right);
    if (t1[root1].right == -1 && t2[root2].right == -1)
        return Compare(t1[root1].left, t2[root2].left);
    if (t1[root1].left == -1 && t2[root2].right == -1)
        return Compare(t1[root1].right, t2[root2].left);
    if (t1[root1].right == -1 && t2[root2].left == -1)
        return Compare(t1[root1].left, t2[root2].right);
    if (t1[root1].left == -1 && t2[root2].left == -1 && t1[root1].right == -1 && t2[root2].right == -1)
        return true;
    if (t1[t1[root1].left].data == t2[t2[root2].left].data)
        return (Compare(t1[root1].left, t2[root2].left) && Compare(t1[root1].right, t2[root2].right));
    else
        return (Compare(t1[root1].left, t2[root2].right) && Compare(t1[root1].right, t2[root2].left));
}

int main() {
    int root1, root2;
    root1 = Read(t1);
    root2 = Read(t2);
    bool flag;
    flag = Compare(root1, root2);
    flag ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}

/*总结：
 c++中NULL为0；
 声明变量后必须得初始化，否则变量的值会很奇怪；
 int arr[常量]{num} 能定义一个包含常量个num的数组（但受编译器影响，有可能会通不过编译
 将char类型的数字变为int类型数字可以用 ch - '0'
*/