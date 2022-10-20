#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    int num[2] = {1, n};
    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
            cout << num[0]++ << " ";
        else
            cout << num[1]-- << " ";
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
    for (int i = 0; i < t; ++i)
        solve();
}

/*

3
1 3 2

5
1 5 2 4 3

6
1 6 2 5 3 4

*/