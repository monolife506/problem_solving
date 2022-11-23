#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n / 2), p(n);
    vector<bool> used(n + 1, false);
    for (int i = 0; i < n / 2; ++i)
    {
        cin >> b[i];
        p[i * 2 + 1] = b[i];
        used[b[i]] = true;
    }

    set<int> nums;
    for (int i = 1; i <= n; ++i)
    {
        if (!used[i])
            nums.insert(i);
    }

    if (nums.size() != n / 2)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = n / 2 - 1; i >= 0; --i)
    {
        if (*nums.begin() >= b[i])
        {
            cout << -1 << '\n';
            return;
        }

        auto it = nums.lower_bound(b[i]);
        it = prev(it);
        p[i * 2] = *it;
        nums.erase(it);
    }

    for (int i = 0; i < n; ++i)
        cout << p[i] << " ";

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

1
8
8 7 2 3

(1, 4) (2, 6) (6, 2) (7, 0)

4 6 2 0

6

(1, 4) (2, 6) (7, 0)

4 6 0

5

(1, 4) (2, 6)

4 6

-1

*/