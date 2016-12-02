#include <iostream>
#include <vector>

using namespace std;

typedef struct heap
{
	int capacity;
	vector<int> element;
}* MinHeap;

MinHeap create(int max)
{
	auto p = new heap;
	p->capacity = max;
	p->element.push_back(max);
	return p;
}

void insert(MinHeap& h, int val)
{
	int it = h->element.size();
	h->element.push_back(val);
	while (val < h->element[it/2])
	{
		h->element[it] = h->element[it / 2];
		it /= 2;
	}
	h->element[it] = val;
}

void road(int index, MinHeap& h, vector<int>& ans)
{
	auto start = index;
	while (start != 0)
	{
		ans.push_back(h->element[start]);
		start /= 2;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	auto H = create(-10000);
	while (n-- != 0)
	{
		int ele;
		cin >> ele;
		insert(H, ele);
	}
	vector<vector<int>> answer;
	while (m-- != 0)
	{
		int start;
		cin >> start;
		vector<int> temp;
		road(start, H, temp);
		answer.push_back(temp);
	}
	for (auto i : answer)
	{
		for (auto k = 0; k < i.size() - 1; k++)
			cout << i[k] << " ";
		cout << i.back() << endl;
	}
}
