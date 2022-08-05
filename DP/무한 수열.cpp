#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;

ll N, P, Q;
unordered_map<ll, ll> cache;

ll dp(ll i)
{
    if (i == 0)
        return 1;
    if (cache.find(i) != cache.end())
        return cache[i];

    return cache[i] = dp(i / P) + dp(i / Q);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> P >> Q;
    cout << dp(N) << '\n';
}