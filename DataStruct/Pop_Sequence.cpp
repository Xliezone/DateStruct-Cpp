/*
Given a stack which can keep MM numbers at most.Push NN numbers in the order of 1, 2, 3, ..., NN and pop randomly.
You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.
For example, if MM is 5 and NN is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification :

Each input file contains one test case.
For each case, the first line contains 3 numbers(all no more than 1000):
MM(the maximum capacity of the stack), NN(the length of push sequence),
and KK(the number of pop sequences to be checked).Then KK lines follow, 
each contains a pop sequence of NN numbers.All the numbers in a line are separated by a space.

Output Specification :

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input :

5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

Sample Output :

YES
NO
NO
YES
NO
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

using Array = vector<int>;

bool judge(int capacity, int length, Array& order)
{
	stack<int> stack;
	
	int num = 0;
	auto it = order.begin();
	while (it != order.end())
	{
		if (stack.empty())
		{
			num++;
			stack.push(num);
		}
		if (*it == stack.top())
		{
			stack.pop();
			++it;
		}
		else
		{
			num++;
			stack.push(num);
		}
		if (stack.size() > capacity || num > length)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int capacity, length, sample;
	cin >> capacity >> length >> sample;
	vector<string> answer;
	while (sample-- != 0)
	{
		Array temp;
		for (auto i = 0; i < length; i++)
		{
			int a;
			cin >> a;
			temp.push_back(a);
		}
		if (judge(capacity, length, temp))
		{
			answer.push_back("YES");
		}
		else
		{
			answer.push_back("NO");
		}
	}

	for (auto& i : answer)
	{
		cout << i << endl;
	}
	return 0;
}
