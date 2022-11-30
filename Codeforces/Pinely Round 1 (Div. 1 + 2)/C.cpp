#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<string> b(n);
    vector<bitset<100>> A(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> b[i];

        A[i][i] = 1;
        for (int j = 0; j < n; ++j)
        {
            if (b[i][j] == '1')
                A[j][i] = 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << A[i].count() << " ";
        for (int j = 0; j < n; ++j)
        {
            if (A[i][j])
                cout << j + 1 << " ";
        }

        cout << '\n';
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

1 2 3 4

1 2
2
3
1 2 3 4


011
101
110

1 2 3
1 2 3
1 2 3

*/