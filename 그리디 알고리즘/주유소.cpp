#include <iostream>
using namespace std;
typedef long long ll;

ll dist[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N - 1; i++)
        cin >> dist[i];

    ll ans = 0, min_cost = INT32_MAX;
    for (size_t i = 0; i < N - 1; ++i)
    {
        ll cost;
        cin >> cost;
        min_cost = min(cost, min_cost);
        ans += dist[i] * min_cost;
    }

    cout << ans << '\n';
}