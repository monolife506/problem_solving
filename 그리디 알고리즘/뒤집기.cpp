#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    int cnt[2] = {};
    if (str[0] == '0')
        cnt[0] = 1;
    else
        cnt[1] = 1;

    for (int i = 1; i < str.length(); ++i)
    {
        if (str[i] != str[i - 1])
            ++cnt[str[i] - '0'];
    }

    cout << min(cnt[0], cnt[1]) << '\n';
}