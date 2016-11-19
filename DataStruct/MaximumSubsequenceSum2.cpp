#include <iostream>
#include <vector>

using namespace std;

//make a queue with linked list

int main() {
	int x;
	cin >> x;
	vector<int> arr;
	int node;
	while (x-- != 0) {
		cin >> node;
		arr.push_back(node);
	}
	int sum = 0;
	int max = arr[0];
	int start = 0;
	int end = arr.size() - 1;
	int temp = start;
	for (size_t i = 0; i < arr.size(); i++) {
		sum += arr[i];
		if (sum < 0) {
			sum = 0;
			temp = i + 1;
			continue;
		}
		if (sum > max) {
			max = sum;
			start = temp;
			end = i;
		}
	}
	if (max < 0) {
		max = 0;
	}
	cout << max << " " << arr[start] << " " << arr[end] << endl;
	return 0;
}