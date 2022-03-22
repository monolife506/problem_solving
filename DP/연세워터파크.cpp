#include <cstring>
#include <deque>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int K[100000];
ll cache[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, D;
    cin >> N >> D;
    for (int i = 0; i < N; ++i)
        cin >> K[i];

    ll ans = K[0];

    deque<P> dq;
    cache[0] = K[0];
    dq.push_back({cache[0], 0});
    for (int i = 1; i < N; ++i)
    {
        cache[i] = max(dq.front().first, 0LL) + K[i];
        ans = max(ans, cache[i]);
        while (!dq.empty() && dq.back().first < cache[i])
            dq.pop_back();
        dq.push_back({cache[i], i});
        while (dq.front().second < (i + 1) - D)
            dq.pop_front();
    }

    cout << ans << '\n';
}
