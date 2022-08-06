#include <iostream>
#include <string>
using namespace std;

int cnt[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;
    for (char c : S)
        cnt[c - 'a']++;
    for (int i = 0; i < 26; ++i)
        cout << cnt[i] << " ";

    cout << '\n';
}