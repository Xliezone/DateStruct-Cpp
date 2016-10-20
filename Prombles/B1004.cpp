#include <iostream>
#include <vector>

using namespace std;

struct Data
{
	string name;
	string number;
	int score;
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<Data> table;

	while (n-- != 0) {
		Data data;
		cin >> data.name >> data.number >> data.score;
		table.push_back(data);
	}

	int max = 0, min = 100;
	Data *tempT, *tempL;	
	for (auto it = table.begin(); it != table.end(); it++) {
		if (it->score >= max) {
			max = it->score;
			tempT = &(*it);
		}
		if (it->score <= min) {
			min = it->score;
			tempL = &(*it);
		}
	}
	cout << tempT->name << " " << tempT->number << endl;
	cout << tempL->name << " " << tempL->number << endl;
	return 0;
}