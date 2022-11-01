#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    int p[2] = {n / 2 + 1, 1};
    for (int i = 0; i < n; ++i)
        cout << p[i % 2]++ << " ";

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


4
3 1 4 2

5
3 1 4 2 5

6
4 1 5 2 6 3

8
5 1 6 2 7 3 8 4


*/