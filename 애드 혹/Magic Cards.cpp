#include <bits/stdc++.h>
#define endl '\n'
// #define FILE_RW
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve()
{
    int n, k, m, f;
    cin >> n >> k >> m >> f;

    unordered_map<int, bitset<100>> mp1;
    unordered_map<bitset<100>, vector<int>> mp2;

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int num;
            cin >> num;

            if (mp1.find(num) == mp1.end())
            {
                bitset<100> mask;
                mask[i] = 1;
                mp1[num] = mask;
            }
            else
            {
                mp1[num][i] = 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (mp1.find(i) == mp1.end())
        {
            bitset<100> mask;
            mp1[i] = mask;
        }
    }

    for (auto &[num, mask] : mp1)
    {
        if (mp2.find(mask) == mp2.end())
            mp2[mask] = vector<int>(1, num);
        else
            mp2[mask].push_back(num);
    }

    for (int i = 0; i < f; ++i)
    {
        string s;
        cin >> s;

        bitset<100> mask;
        for (int j = 0; j < k; ++j)
            mask[j] = (s[j] == 'Y');

        if (mp2.find(mask) != mp2.end() && mp2[mask].size() == 1)
            cout << mp2[mask].front() << endl;
        else
            cout << 0 << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    solve();
}