#include <iostream>
using namespace std;

int main()
{ 
    int N;
    cin >> N; // 이 풀이에서는 없어도 무방한 수임

    string str;
    cin >> str;

    int total = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        total += str[i] - '0';
    }
    cout << total;
}