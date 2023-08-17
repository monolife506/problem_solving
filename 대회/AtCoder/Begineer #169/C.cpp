#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll A;
    string B;
    cin >> A >> B;

    ll B2 = ((B[0] - '0') * 100) + ((B[2] - '0') * 10) + (B[3] - '0');
    ll ans = (A * B2) / 100;

    cout << ans << '\n';
}