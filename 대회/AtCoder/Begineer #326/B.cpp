#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = n; i <= 999; ++i)
    {
        if ((i / 100) * ((i / 10) % 10) == i % 10)
        {
            cout << i << '\n';
            return 0;
        }
    }
}