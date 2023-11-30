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

    int x, y;
    cin >> x >> y;

    if (x < y && y - x <= 2)
        cout << "Yes" << '\n';
    else if (x > y && x - y <= 3)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}