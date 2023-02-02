#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    map<vector<int>, bool> inverse_flag;
    for (int i = 0; i < n; ++i)
    {
        vector<int> inverse(m);
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            inverse[a[i][j] - 1] = j + 1;
        }

        vector<int> tmp;
        for (int j = 0; j < m; ++j)
        {
            tmp.push_back(inverse[j]);
            inverse_flag[tmp] = true;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int beauty = 0;

        vector<int> v;
        for (int j = 0; j < m; ++j)
        {
            v.push_back(a[i][j]);
            if (!inverse_flag[v])
                break;

            beauty++;
        }

        cout << beauty << " ";
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

p * q = (1, 2, 3, 4)
p = (1, 2, 3, 4) * q^(-1) = (1, 2, 3, 4) * p

q * q^(-1) = (1, 2, 3, 4)

3 1 4 2
1 2 4 3
2 1 3 4


*/