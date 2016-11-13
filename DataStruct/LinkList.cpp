#include <iostream>

using namespace std;

typedef int ElemType;

struct Node {
    ElemType data;
    Node *next;
};

class LinkList {
private:
    Node *Head;
public:
    LinkList();

    ~LinkList();

    void creat();

    void display();

    void insert(int i, ElemType x);

    void insert2(ElemType x, ElemType y);

    void delet2(ElemType x);

    ElemType delet(int i);
};

LinkList::LinkList() {
    Head = new Node;
    Head->next = nullptr;
    Head->data = 0;
    cout << "\n init" << endl;
}

LinkList::~LinkList() {
    Node *p = Head->next;
    while (p != nullptr) {
        Head->next = p->next;
        delete p;
        p = Head->next;
    }
    cout << "\n 链表已删除" << endl;
}

void LinkList::creat() {
    Node *s;
    Node *h = Head;
    ElemType x;
    cout << "\n -999" << endl;
    cin >> x;
    while (x != -999) {
        s = new Node;
        s->data = x;
        h->next = s;
        h = s;
        h->next = nullptr;
        cin >> x;
    }
    cout << "\n over" << endl;
}

void LinkList::display() {
    Node *p = Head->next;
    while (p) {
        cout << p->data << endl;
        p = p->next;
    }
    cout << "\n over" << endl;
}

void LinkList::insert(int i, ElemType x) {
    int k = 0;
    Node *h = Head;
    Node *p;
    while (h && k < i) {
        k++;
        p = h;
        h = h->next;
    }
    if (k == i) {
        Node *s = new Node;
        s->data = x;
        p->next = s;
        s->next = h->next;
        cout << "insert success!" << endl;
    } else {
        cout << "insert failed!" << endl;
    }
    cout << "over!" << endl;
}

ElemType LinkList::delet(int i) {
    int k = 0;
    Node *h = Head, *q;
    ElemType x = 0;
    while (h && k < i) {
        k++;
        q = h;
        h = h->next;
    }
    if (k == i) {
        x = h->data;
        q->next = h->next;
        delete h;
        cout << "delete success!" << endl;
    } else {
        cout << "delete failed!" << endl;
    }
    cout << "over!" << endl;
    return x;
}

void LinkList::insert2(ElemType x, ElemType y) {
    Node *s = new Node;
    s->data = y;
    Node *h = Head, *q;
    while (h && h->data != x) {
        h = h->next;
        q = h->next;
    }
    h->next = s;
    s->next = q;
}

void

int main() {
    LinkList L;
    L.creat();
    L.display();
    L.insert(2, 100);
    L.display();
    cout << L.delet(2) << endl;
    L.display();
    system("pause");
    return 0;
}