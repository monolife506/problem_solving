#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';

    int num = n + (n / 2) + 2;
    for (int i = 1; i <= n; i += 2)
    {
        cout << i << " " << num - i << '\n';
        num++;
    }
    for (int i = 2; i <= n; i += 2)
    {
        cout << i << " " << num - i << '\n';
        num++;
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

3
1 2 3
4 5 6

1 5
3 4
2 6

5
1 2 3 4 5
6 7 8 9 10

1 8
3 7
5 6
2 10
4 9

7
1 2 3 4 5 6 7
8 9 10 11 12 13 14

*/