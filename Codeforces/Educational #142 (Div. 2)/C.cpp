#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> idx(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int p;
        cin >> p;
        idx[p] = i;
    }

    if (n == 1)
    {
        cout << 0 << '\n';
    }
    else
    {
        int l_idx = idx[(n % 2 == 0) ? n / 2 : n / 2 + 1];
        int r_idx = idx[n / 2 + 1];

        if (l_idx > r_idx)
        {
            cout << n / 2 << '\n';
            return;
        }

        int l_num = (n % 2 == 0) ? n / 2 - 1 : n / 2;
        int r_num = n / 2 + 2;
        for (int i = (n % 2 == 0 ? n / 2 - 1 : n / 2); i > 0; --i)
        {
            if (idx[l_num] > l_idx || idx[r_num] < r_idx)
            {
                cout << i << '\n';
                return;
            }

            l_idx = idx[l_num--];
            r_idx = idx[r_num++];
        }

        cout << 0 << '\n';
    }
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

max -> n / 2
1 2 3 6 4 5

1


1

3
3
1 3 2
5
1 2 3 5 4
5
1 2 4 5 3

1
1
2

2
5
1 2 4 5 3
5
2 4 3 5 1

2
2

*/