//postfix
#include <iostream>
#include <vector>

using namespace std;

int postfix(){
    string in;
    cin >> in;
    vector<int> stack;
    for (auto s : in) {
        if (isdigit(s)) {
            stack.push_back(s-48);//s为char类型，因此使用ascii编码，48=0，65=A，97=a
//            cout << s << endl << s-48<< endl;
        }
        else {
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            if (s == '+')
                stack.push_back(a + b);
            else if (s == '-')
                stack.push_back(a - b);
            else if(s == '*')
                stack.push_back(a * b);
            else if(s == '/')
                stack.push_back(a / b);
            else
                cout << "this should use ascii" << endl;
        }
    }
    cout << stack.back() << endl;
}
int main(int arg, char const *argv[]){
    postfix();
    return 0;
}