#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
    string local;
    int num;
    Node *next;
};

typedef Node *List;

struct tempNode {
    string local;
    int num;
    string next;
};

void Read(std::vector<tempNode> &tempList) {
    string start;
    int N;
    string K;
    cin >> start >> N >> K;
    tempNode node;
    node.local = start;
    node.num = N;
    node.next = K;
    tempList.push_back(node);
    for (int i = 0; i < N; ++i) {
        tempNode node;
        cin >> node.local >> node.num >> node.next;
        tempList.push_back(node);
    }
}

void sort(std::vector<tempNode> &tempList) {
    for (int i = 1; i < tempList.size(); ++i) {
        for (int j = i; j < tempList.size(); ++j) {
            if (tempList[j].num == i) {
                tempNode temp = tempList[j];
                tempList[j] = tempList[i];
                tempList[i] = temp;
            }
        }
    }
}

List Link(std::vector<tempNode> &tempList, List &list) {
    List rear;
    rear = list;
    for (int i = 1; i < tempList.size(); i++) {
//        List node;
//        node = (List) new Node;
//        node->local = tempList[i].local;
//        node->num = tempList[i].num;
//        rear->next = node;
//        rear = rear->next;
        rear->local = tempList[i].local;
        rear->num = tempList[i].num;
        List node;
        node = (List) new Node;
        rear->next = node;
        rear = rear->next;
    }
    return list;
}

List reserve(List &list, int N, int K) {
    List New, Old, Temp, head, Lhead;
    head = list;
    Lhead = head;
    int k = 0;
    while (k < K) {
        New = head;
        Old = head->next;
        int n = 1;
        while (n < N) {
            Temp = Old->next;
            Old->next = New;
            New = Old;
            Old = Temp;
            n++;
        }
        if (k == 0)
            list = New;
        if (k > 0) {
            Lhead->next = New;
            Lhead = head;
        }
        k++;
        if (k == K) {
            head->next = Old;
        }
        head = Old;
//        head->next = Old;
//        if (k == 0)
//            list = New;
//        else {
//            Lhead->next = New;
//        }
//        Lhead = head;
    }
    return list;
}

void Print(List &list, int N) {
    List li = list;
    for (int i = 0; i < N; ++i) {
        if (i != N - 1)
            cout << li->local << " " << li->num << " " << li->next->local << endl;
        else
            cout << li->local << " " << li->num << " " << "-1" << endl;
        li = li->next;
    }
}

int main(int argc, char const *argv[]) {
    vector<tempNode> tempList;
    Read(tempList);
    sort(tempList);
    List list = (List) new Node;
    list = Link(tempList, list);
    int N = tempList[0].num;
    stringstream ss;
    ss << tempList[0].next;
    int K;
    ss >> K;
    int round = N / K;
    list = reserve(list, K, round);
    Print(list, N);
    return 0;
}