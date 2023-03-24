#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    multiset<int> a;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        a.insert(num);
    }

    vector<int> b(n, -1);
    b[0] = *max_element(a.begin(), a.end());

    cout << b[0] << " ";
    a.erase(a.find(b[0]));

    int i = 0;
    while (true)
    {
        if (++i >= 32)
            break;

        int ans = -1;
        for (int num : a)
        {
            if (b[i] < (b[i - 1] | num))
            {
                b[i] = (b[i - 1] | num);
                ans = num;
            }
        }

        if (ans == -1)
            break;

        cout << ans << " ";
        a.erase(a.find(ans));
    }

    for (int num : a)
        cout << num << " ";

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

1000
0100
0001
0010

*/