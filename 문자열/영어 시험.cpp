#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string str;
    cin >> str;
    for (int i = 0; i < N; ++i)
        cout << str;

    cout << '\n';
}

/*

3
abc

abc
acb
bac
bca
cab
cba

aab
bba
bbc
ccb
aac
cca

aaa
bbb
ccc

abcabcabc

*/