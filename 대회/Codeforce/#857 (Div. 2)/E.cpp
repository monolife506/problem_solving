#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n);
    map<int, vector<int>> idx;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;

        int max_val = 0;
        for (int j = 0; j < k; ++j)
        {
            int val;
            cin >> val;
            if (max_val < val)
            {
                max_val = val;
                a[i].push_back(val);
                idx[val].push_back(i);
            }
        }
    }

    vector<int> cache(n, 0);
    int pre = 0;
    for (auto p : idx)
    {
        int i = p.first;
        int nxt = 0;
        for (int j : p.second)
        {
            if (i == a[j].back())
            {
                cache[j] = max(cache[j] + 1, pre + 1);
                nxt = max(nxt, cache[j]);
            }
            else if (i == a[j].front())
            {
                cache[j] = pre + 1;
            }
            else
            {
                cache[j] = max(cache[j] + 1, pre + 1);
            }
        }

        pre = max(pre, nxt);
    }

    cout << *max_element(cache.begin(), cache.end()) << '\n';
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

4 9
7
8
1

3 4
1 8
2 8
7 9

dp공부 꾸준히 다시 해야할듯

*/