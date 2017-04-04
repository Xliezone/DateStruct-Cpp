#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> Map;

long long Ten(string a, long long radix)
{
    long long ans = 0;
    for (auto i = 0; i < a.size(); i++)
    {
        ans = ans*radix + Map[a[i]];
    }
    return ans;
}

int FindLeastRadix(string b){
    int temp = 0;

    for (auto i = 0; i < b.size(); i++){
        if (Map[b[i]] > temp)
            temp = Map[b[i]];
    }

    return temp+1;
}

int Compare(long long a_ten, string b, long long radix){
    int flag;
    long long b_ten = Ten(b, radix);
    if (b_ten < 0) //overflow
        flag = -1;
    else if (a_ten == b_ten)
        flag = 0;
    else if (a_ten < b_ten)
        flag = -1;
    else
        flag = 1;
    return flag;
}

long long BinarySearch(long long a_ten, string b, long long low, long long high){
    long long mid;
    while (low <= high){
        mid = (low + high)/2;
        int  flag = Compare(a_ten, b, mid);
        if (flag == 0) return mid;
        else if (flag == 1) low = mid +1;
        else high = mid -1;
    }
    return -1;
}

int main()
{
    string a, b;
    int flag, radix;
    cin >> a >> b >> flag >> radix;

    for (char i = '0'; i <= '9'; i++)
    {
        Map[i] = i - '0';
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        Map[i] = i - 'a' + 10;
    }

    if (flag == 2){
        swap(a ,b);
    }

    long long a_ten = Ten(a, radix);
    long long low = FindLeastRadix(b);
    long long high = max(low, a_ten)+1;
    long long ans = BinarySearch(a_ten, b, low, high);
    if (ans == -1)
        cout << "Impossible";
    else
        cout << ans;
}