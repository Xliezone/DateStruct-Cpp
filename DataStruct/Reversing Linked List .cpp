#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Node {
    string last;
    int num;
    string next;
};

void Read(vector<Node> &list) {
    string start;
    int Len;
    string N;
    cin >> start >> Len >> N;
    Node node;
    node.last = start;
    node.num = Len;
    node.next = N;
    list.push_back(node);
    for (int i = 0; i < Len; i++) {
        string last;
        int num;
        string next;
        cin >> last >> num >> next;
        Node node;
        node.last = last;
        node.num = num;
        node.next = next;
        list.push_back(node);
    }
}

//index 初始值为0;
void Build(vector<Node> &list, int index, vector<Node> &orderList) {
    string first;
    if (!index)
        first = list[index].last;
    else
        first = list[index].next;
    for (int i = 1; i < list.size(); i++) {
        if (first == list[i].last) {
            orderList.push_back(list[i]);
            index = i;
            Build(list, index, orderList);
            break;
        }
    }
}

void Order(int N, vector<Node> &orderList) {
    if (orderList.size() / N == 0)
        return;
    int round = orderList.size() / N;
    for (int j = 0; j < round; j++) {
        for (int i = 0; i < N / 2; i++) {
            Node temp = orderList[i + N*j];
            orderList[i + N*j] = orderList[N*(2*j+1)-1-i-N*j];
            orderList[N*(2*j+1)-1-i-N*j] = temp;
        }
    }

    for (int i = 0; i < orderList.size(); i++) {
        if (i < orderList.size()-1)
        orderList[i].next = orderList[i + 1].last;
        else
            orderList[i].next = "-1";
    }
}

void Print(vector<Node> &orderList) {
    for (int i = 0; i < orderList.size(); i++) {
        cout << orderList[i].last << " " << orderList[i].num << " " << orderList[i].next << endl;
    }
}

int main(int argc, char const *argv[]) {
    /*read data
    build list
    change the order
    print*/

    vector<Node> list;
    Read(list);
    vector<Node> orderList;
    Build(list, 0, orderList);
    stringstream ss;
    ss << list[0].next;
    int N;
    ss >> N;
    Order(N, orderList);
    Print(orderList);
    return 0;
}
