#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;

    set<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        nums.insert(num);
    }

    if (nums.size() == 1)
        cout << 1 << '\n';
    else if (nums.size() == 2)
        cout << n / 2 + 1 << '\n';
    else
        cout << n << '\n';
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

1 2 1 2


*/