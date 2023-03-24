#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int min_a = *min_element(a.begin(), a.end());
    if (a[0] == min_a)
        cout << "Bob" << '\n';
    else
        cout << "Alice" << '\n';
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

n == 3


2 2 4
1 2 4

2 1 4
1 1 4

0 1 4
1 0 4






*/