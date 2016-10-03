#include <iostream>
#include <string>
#include <vector>

using namespace std;

void judge(string &s, vector<string> &answer) {
	if (s.find_first_not_of(" PAT") != string::npos) {
		answer.push_back("NO");
	} else {
		auto length = s.size();
		auto p = s.find('P');
		auto t = s.find('T');
		if (p == string::npos || t == string::npos || t-p <= 1) {
			answer.push_back("NO");
		} else {
			string a(s, 0, p);
			string b(s, p+1, t-p-1);
			string c(s, t+1, length-t-1);
			string abc = a+b+c;
			if (abc.find_first_not_of(" A") != string::npos) {
				answer.push_back("NO");
				return;
			}
			if (p == 0 && t == length-1) 
				answer.push_back("YES");
			else if (p * (t-p-1) == (length-1-t))
				answer.push_back("YES");
			else
				answer.push_back("NO");
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<string> answer;
	int i = 0;
	while(i++ < n) {
		string s;
		cin >> s;
		judge(s, answer);
	}
	for (auto s : answer) {
		cout << s << endl;
	}
	return 0;
}