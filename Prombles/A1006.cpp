#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int M;
    scanf("%d", &M);

    string early;
    string last;

    int earlyTime = 99999999;
    int lastTime = 0;

    for (auto i = 0; i < M; i++)
    {
        string name;
        cin >> name;
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int temp = h*3600 + m*60 + s;
        if (temp < earlyTime){
            earlyTime = temp;
            early = name;
        }
        scanf("%d:%d:%d", &h, &m, &s);
        temp = h*3600 + m*60 + s;
        if (temp > lastTime){
            lastTime = temp;
            last = name;
        }
    }

    cout << early << " " << last << endl;
}