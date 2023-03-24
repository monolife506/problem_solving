#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve()
{
    int n, k;
    cin >> n >> k;

    int num[2] = {n, 1};
    for (int i = 0; i < n; ++i)
        cout << ((i % 2 == 0) ? num[0]-- : num[1]++) << " ";

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

5 1 4 2 3

*/