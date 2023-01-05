#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;

bool cmp(pair<vector<string>, int> &lhs, pair<vector<string>, int> &rhs)
{
    int ld = 0, rd = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        for (int j = 1; j < m - 1; ++j)
        {
            if (lhs.first[i][j] != rhs.first[i][j])
            {
                if (lhs.first[i][j] != rhs.first[i][j - 1])
                    rd++;
                else
                    ld++;
            }
        }
    }

    return (ld != rd) ? ld < rd : lhs.second < rhs.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    vector<pair<vector<string>, int>> pictures(k + 1);
    for (int i = 0; i < k + 1; ++i)
    {
        pictures[i].first.resize(n);
        pictures[i].second = i;
        for (int j = 0; j < n; ++j)
            cin >> pictures[i].first[j];
    }

    sort(pictures.begin(), pictures.end(), cmp);

    vector<tuple<int, int, int>> ans;
    for (int p = 1; p < k + 1; ++p)
    {
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 1; j < m - 1; ++j)
            {
                if (pictures[p - 1].first[i][j] != pictures[p].first[i][j])
                    ans.push_back({1, i + 1, j + 1});
            }
        }

        ans.push_back({2, pictures[p].second + 1, 0});
    }

    cout << pictures[0].second + 1 << '\n'
         << ans.size() << '\n';

    for (tuple<int, int, int> t : ans)
    {
        cout << get<0>(t) << " ";
        if (get<0>(t) == 1)
            cout << get<1>(t) << " " << get<2>(t) << '\n';
        else
            cout << get<1>(t) << '\n';
    }
}

/*

01110
11111
11111
11111
01110

*/