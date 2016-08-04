//infix2postfix
#include <iostream>
#include <vector>

using namespace std;

void in2post() {
    string infix;
    cin >> infix;
    vector<char> stack;
    string postfix;
    for (auto s : infix) {
        if (isdigit(s)) {
            postfix += s;
        }
        else {
            if (s == '+' || s == '-') {
                if (stack.empty() || stack.back() == '(')
                    stack.push_back(s);
                else {
                    while (stack.back() != '(' && !stack.empty()) {
                        postfix += stack.back();
                        stack.pop_back();
                    }
                    stack.push_back(s);
                }
            } else if (s == '*' || s == '/') {
                if (stack.empty() || stack.back() == '(' || stack.back() == '+' || stack.back() == '-')
                    stack.push_back(s);
                else {
                    postfix += stack.back();
                    stack.pop_back();
                    stack.push_back(s);
                }
            } else if (s == '('){
                stack.push_back(s);
            } else if (s == ')') {
                while (stack.back() != '(') {
                    postfix += stack.back();
                    stack.pop_back();
                }
                stack.pop_back();
            }
        }
    }
    while (!stack.empty()) {
        postfix += stack.back();
        stack.pop_back();
    }
    cout << postfix << endl;
}

int main(int argc, char const *argv[]) {
    in2post();
    return 0;
}