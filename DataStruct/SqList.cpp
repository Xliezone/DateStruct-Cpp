#include <iostream>
#include <iomanip>

using namespace std;

class SqList {
private:
	int *elem;
	int len;
	int maxlen;
public:
	SqList() = default;

	SqList(int);

	~SqList();

	void Create();

	void PrintOut();

	void Insert(int, int);

	int Delete(int);
};

SqList::SqList(int i) : maxlen(i) {
	elem = new int[maxlen];
	len = 0;
}

SqList::~SqList() { delete[]elem; }

void SqList::Create() {
	cout << "\n Input length=";
	cin >> len;
	cout << "\n Input Data:\n";
	for (int i = 0; i < len; i++) {
		cin >> elem[i];
	}
}

void SqList::PrintOut() {
	cout << "\n length=" << len;
	cout << "\n PrintOut Data:\n";
	for (int i = 0; i < len; i++) {
		cout << setw(6) << elem[i];
	}
	cout << endl;
}

void SqList::Insert(int number, int index) {
	if (index < 0 || index > maxlen)
		cout << "ERROR" << endl;
	else {
		for (int i = len; i > index; i--) {
			elem[i] = elem[i - 1];
		}
		len++;
		elem[index] = number;
	}
}

int SqList::Delete(int index) {
	if (index < 0 || index > len) {
		cout << "ERROR" << endl;
		return 0;
	}
	else {
		int x = elem[index];
		for (auto i = index; i < len; i++) {
			elem[i] = elem[i + 1];
		}
		len--;
		return x;
	}
}

int main(int argc, char const *argv[]) {
	SqList L(10);
	L.Create();
	L.PrintOut();
	L.Insert(100, 2);
	L.Delete(0);
	L.PrintOut();
	system("pause");
	return 0;
}