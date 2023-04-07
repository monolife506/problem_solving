#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int l = 0;
    cout << 1 << " ";
    for (int i = 1; i < n; ++i)
    {
        while (a[l] < i - l + 1)
            l++;
        cout << i - l + 1 << " ";
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

3
3 * 2 / 2

4
4 * 3 / 2

5
5 * 4 / 2
5 * 4 * 3 / 2 * 3

6
6 * 5 / 2
6 * 5 * 4 / 2 * 3

7
7 * 6 / 2
7 * 6 * 5 / 2 * 3
7 * 6 * 5 * 4 / 2 * 3 * 4

*/