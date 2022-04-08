#include <iostream>
using namespace std;
typedef long long ll;

size_t N;
ll x[100000];

ll get_sum(ll d)
{
    ll ret = 0;
    for (ll i = 0; i < N; ++i)
        ret += abs(x[i] - d * i);
    return ret;
}

ll ternary_search(ll l, ll r)
{
    ll ret = INT64_MAX;

    while (r - l >= 3)
    {
        ll p = (l * 2 + r) / 3;
        ll q = (l + r * 2) / 3;
        if (get_sum(p) > get_sum(q))
            l = p;
        else
            r = q;
    }

    for (ll i = l; i <= r; ++i)
        ret = min(ret, get_sum(i));

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> x[i];

    cout << ternary_search(0, x[N - 1]) << '\n';
}