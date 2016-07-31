//practise_3.6
#include <iostream>
#include <vector>

using namespace std;

typedef struct Node {
    Node *prev = 0;
    int value;
    Node *next = 0;
} *LoopList;

vector<int> josephus(int M, int N) {
    LoopList p, head;
    head = new Node;
    p = head;
    int n = 1;
    while (n <= N) {
        p->next = new Node;
        p->next->prev = p;
        p = p->next;
        p->value = n;
        n++;
    }
    p->next = head->next;
    head->next->prev = p;
    int m = 0;
    int left = N;
    p = head->next;
    vector<int> out;
    while (left != 0) {
        if (m != M) {
            p = p->next;
            m++;
        }
        else{
            m = 0;
            out.push_back(p->value);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            LoopList temp = p;
            p = p->next;
            delete temp;
            left--;
        }
    }
    return out;
}

int main(int argc, char const *argv[]) {
    vector<int> out = josephus(1, 5);
    return 0;
}