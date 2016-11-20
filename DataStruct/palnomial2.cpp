#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int xishu;
	int zhishu;
};

typedef vector<Node> Array;

void multi(Array &y1, Array &y2, Array &y) {
	for (auto &i : y1) {
		for (auto &j : y2) {
			Node temp;
			temp.xishu = i.xishu * j.xishu;
			temp.zhishu = i.zhishu + j.zhishu;
			bool flag = false;
			for (auto &k : y) {
				if (temp.zhishu == k.zhishu) {
					k.xishu += temp.xishu;
					flag = true;
					break;
				}
			}
			if (!flag) {
				y.push_back(temp);
			}
		}
	}
	for (size_t i = 0; i < y.size(); i++) {
		for (size_t j = i + 1; j < y.size(); j++) {
			if (y[i].zhishu < y[j].zhishu) {
				auto temp = y[i];
				y[i] = y[j];
				y[j] = temp;
			}
		}
	}
	Array temp;
	for (size_t i = 0; i < y.size(); i++) {
		if (y[i].xishu != 0) {
			temp.push_back(y[i]);
		}
	}
	if (temp.size() == 0) {
		Node t;
		t.xishu = 0;
		t.zhishu = 0;
		temp.push_back(t);
	}
	y = temp;
}

void plus(Array &y1, Array &y2, Array &y) {
	auto i = y1.begin();
	auto j = y2.begin();
	while (i != y1.end() && j != y2.end()) {
		if (i->zhishu == j->zhishu) {
			Node temp;
			temp.xishu = i->xishu + j->xishu;
			temp.zhishu = i->zhishu;
			if (temp.xishu != 0)
			y.push_back(temp);
			i++;
			j++;
		}
		else if (i->zhishu > j->zhishu) {
			y.push_back(*i);
			i++;
		}
		else {
			y.push_back(*j);
			j++;
		}
	}
	while (i != y1.end()) {
		y.push_back(*i);
		i++;
	}
	while (j != y2.end()) {
		y.push_back(*j);
		j++;
	}
	if (y.size() == 0) {
		Node temp;
		temp.xishu = 0;
		temp.zhishu = 0;
		y.push_back(temp);
	}
}

void display(Array &y) {
	for (size_t i = 0; i < y.size(); i++) {
		cout << y[i].xishu << " " << y[i].zhishu;
		if (i != y.size() - 1)
			cout << " ";
	}
	cout << endl;
}

int main() {
	Array y1;
	Array y2;
	int n;
	cin >> n;
	if (n != 0) {
		while (n-- != 0) {
			Node node;
			cin >> node.xishu >> node.zhishu;
			y1.push_back(node);
		}
	}
	else {
		Node t;
		t.xishu = 0;
		t.zhishu = 0;
		y1.push_back(t);
	}
	cin >> n;
	if (n != 0) {
		while (n-- != 0) {
			Node node;
			cin >> node.xishu >> node.zhishu;
			y2.push_back(node);
		}
	}
	else {
		Node t;
		t.xishu = 0;
		t.zhishu = 0;
		y2.push_back(t);
	}
	Array p1, p2;
	multi(y1, y2, p1);
	::plus(y1, y2, p2);
	display(p1);
	display(p2);
	return 0;
}