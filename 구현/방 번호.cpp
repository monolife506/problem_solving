#include <iostream>
#include <string>
using namespace std;

int cnt[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    for (char c : str)
        ++cnt[c - '0'];

    int ans = 0;
    for (int i = 0; i <= 9; ++i)
    {
        if (i == 6 || i == 9)
            continue;

        ans = max(ans, cnt[i]);
    }

    if (cnt[6] + cnt[9] > ans * 2)
    {
        ans = (cnt[6] + cnt[9]) / 2;
        if ((cnt[6] + cnt[9]) % 2 == 1)
            ++ans;
    }

    cout << ans << '\n';
}