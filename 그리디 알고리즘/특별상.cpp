#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

P p[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        cin >> p[i].first >> p[i].second;

    sort(p, p + N, [](P &lhs, P &rhs) -> bool
         { return lhs.second > rhs.second; });
    sort(p + K, p + N, [](P &lhs, P &rhs) -> bool
         { return lhs.first > rhs.first; });

    ll ans = 0;
    for (int i = 0; i < M + K; ++i)
        ans += p[i].first;

    cout << ans << '\n';
}