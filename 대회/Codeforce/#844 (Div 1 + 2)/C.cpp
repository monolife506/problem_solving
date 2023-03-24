#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pii> cnt(26);
    for (int i = 0; i < 26; ++i)
        cnt[i] = {0, i};
    for (char c : s)
        cnt[c - 'a'].first++;

    sort(cnt.begin(), cnt.end(), greater<pii>());

    int ans = n, k = -1;
    for (int i = 1; i <= 26; ++i)
    {
        if (n % i != 0)
            continue;

        int val = 0;
        for (int j = 0; j < i && cnt[j].first > n / i; ++j)
            val += cnt[j].first - (n / i);
        for (int j = i; j < 26 && cnt[j].first > 0; ++j)
            val += cnt[j].first;

        if (ans > val)
        {
            ans = val;
            k = i;
        }
    }

    queue<char> c;
    for (int i = 0; i < k && cnt[i].first > n / k; ++i)
    {
        for (int j = 0; j < cnt[i].first - (n / k); ++j)
            c.push(cnt[i].second);
    }
    for (int i = k; i < 26 && cnt[i].first > 0; ++i)
    {
        for (int j = 0; j < cnt[i].first; ++j)
            c.push(cnt[i].second);
    }

    vector<queue<char>> v(26);
    for (int i = 0; i < k; ++i)
    {
        if (cnt[i].first >= n / k)
            continue;

        for (int j = 0; j < (n / k) - cnt[i].first; ++j)
        {
            v[c.front()].push(cnt[i].second);
            c.pop();
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < n; ++i)
    {
        if (!v[s[i] - 'a'].empty())
        {
            cout << (char)('a' + v[s[i] - 'a'].front());
            v[s[i] - 'a'].pop();
        }
        else
        {
            cout << s[i];
        }
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

6 4 3 2


5 5 5

*/