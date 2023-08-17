#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N;
    cin >> N;

    ll ans = 0;
    for (ll i = 1; i <= (ll)1e6; ++i)
    {
        string str = to_string(i);
        str += str;
        if (stol(str) > N)
            break;

        ans++;
    }

    cout << ans << '\n';
}