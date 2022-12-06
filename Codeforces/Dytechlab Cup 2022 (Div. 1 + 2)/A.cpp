#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> cnt(26, 0), ans(26, 0);
    for (char c : s)
        cnt[c - 'a']++;

    int remain = k;
    for (int i = 0; i < min(25, n / k); ++i)
    {
        if (remain > cnt[i])
        {
            ans[i] = remain - cnt[i];
            remain = cnt[i];
        }
    }

    if (remain > 0)
        ans[min(25, n / k)] = remain;

    for (int i = min(25, n / k); i >= 0; --i)
    {
        for (int j = 0; j < ans[i]; ++j)
            cout << (char)('a' + i);
    }

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

15 5

aaa
bbbbbbbbb
ccc


cbbba
cbbba
cbbba

ddd

*/