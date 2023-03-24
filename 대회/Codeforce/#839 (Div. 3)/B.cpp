#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int arr[2][2];
    cin >> arr[0][0] >> arr[0][1] >> arr[1][0] >> arr[1][1];

    for (int i = 0; i < 4; ++i)
    {
        if (arr[0][0] < arr[0][1] && arr[1][0] < arr[1][1] && arr[0][0] < arr[1][0] && arr[0][1] < arr[1][1])
        {
            cout << "YES" << '\n';
            return;
        }

        int tmp = arr[0][0];
        arr[0][0] = arr[1][0];
        arr[1][0] = arr[1][1];
        arr[1][1] = arr[0][1];
        arr[0][1] = tmp;
    }

    cout << "NO" << '\n';
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