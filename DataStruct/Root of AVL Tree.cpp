#include <iostream>

typedef struct Node {
    int val;
    Node *left, *right;
    int height;
} *Tree;

int Max(int a, int b) {
    return a > b ? a : b;
}

int GetHeight(Tree &tree) {
    return (tree == 0) ? 0 : tree->height;
}

Tree left_left_rotation(Tree &root) {
    Tree temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    //update height
    root->height = Max(GetHeight(root->left), GetHeight(root->right)) + 1;
    temp->height = Max(GetHeight(temp->left), GetHeight(temp->right)) + 1;
    return temp;
}

Tree right_right_rotation(Tree &root) {
    Tree temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root->height = Max(GetHeight(root->left), GetHeight(root->right)) + 1;
    temp->height = Max(GetHeight(temp->left), GetHeight(temp->right)) + 1;
    return temp;
}

Tree left_right_rotation(Tree &root) {
    root->left = right_right_rotation(root->left);
    return left_left_rotation(root);
}

Tree right_left_rotation(Tree &root) {
    root->right = left_left_rotation(root->right);
    return right_right_rotation(root);
}

Tree Insert(int num, Tree &tree) {
    if (tree == 0) {
        Tree node = (Tree) new Node;
        node->val = num;
        node->left = 0;
        node->right = 0;
        node->height = 0;
        tree = node;
    }
    else {
        if (num < tree->val) {
            tree->left = Insert(num, tree->left);
            if (GetHeight(tree->left) - GetHeight(tree->right) == 2) {
                if (num < tree->left->val)
                    //left_left
                    tree = left_left_rotation(tree);
                else
                    //left_right
                    tree = left_right_rotation(tree);
            }
        }
        else if (num > tree->val) {
            tree->right = Insert(num, tree->right);
            if (GetHeight(tree->right) - GetHeight(tree->left) == 2) {
                if (num > tree->right->val)
                    //right_right
                    tree = right_right_rotation(tree);
                else
                    //right_left
                    tree = right_left_rotation(tree);
            }
        }
    }
    tree->height = Max(GetHeight(tree->left), GetHeight(tree->right)) + 1;
    return tree;
}

int main() {
    int N;
    std::cin >> N;
    Tree tree = 0;
    int num;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        tree = Insert(num, tree);
    }
    if (tree != 0)
        std::cout << tree->val;
    else
        std::cout << 0;
    return 0;
}