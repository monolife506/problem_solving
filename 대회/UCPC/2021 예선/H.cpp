#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll cache[12][100001];
vector<P> graph[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(cache, -1, sizeof(cache));

    int N, M, K, S, T;
    cin >> N >> M >> K >> S >> T;
    for (int i = 1; i <= M; ++i)
    {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
        graph[b].push_back({a, 0});
    }

    cache[0][S] = 0;
    for (int k = 0; k <= K; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            if (cache[k][i] != -1)
            {
                for (P &p : graph[i])
                {
                    if (i < p.first)
                        cache[k][p.first] = max(cache[k][p.first], cache[k][i] + p.second);
                    else if (k < K)
                        cache[k + 1][p.first] = max(cache[k + 1][p.first], cache[k][i] + p.second);
                }
            }
        }
    }

    ll ans = -1;
    for (int k = 0; k <= K; ++k)
        ans = max(ans, cache[k][T]);

    cout << ans << '\n';
}