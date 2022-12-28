#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> cache[19];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int max_p = pow(2, n);
    for (int i = 1; i <= max_p; ++i)
        cache[0].push_back(i);

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
        {
            for (int j = 0; j < cache[i].size() / 2; ++j)
                cache[i + 1].push_back(cache[i][j]);
        }
        else
        {
            for (int j = 1; j < cache[i].size(); j += 2)
                cache[i + 1].push_back(cache[i][j]);
        }
    }

    int min_x = cache[n][0];

    for (int i = 0; i <= n; ++i)
        cache[i].clear();
    for (int i = max_p; i >= 1; --i)
        cache[0].push_back(i);

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            for (int j = 0; j < cache[i].size() / 2; ++j)
                cache[i + 1].push_back(cache[i][j]);
        }
        else
        {
            for (int j = 1; j < cache[i].size(); j += 2)
                cache[i + 1].push_back(cache[i][j]);
        }
    }

    int max_x = cache[n][0];

    for (int i = min_x; i <= max_x; ++i)
        cout << i << " ";

    cout << '\n';
}

/*

101

1 2 3 4 5 6 7 8
2 4 6 8
2 4
4

1 2 3 4 5 6 7 8
5 6 7 8
5 7
7

*/