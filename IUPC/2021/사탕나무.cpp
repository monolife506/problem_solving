#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;
const int MAX_K = 20;

int N, K;
vector<int> tree[MAX_N + 1];

int cache[MAX_K + 1][MAX_N + 1];

int calculate()
{
    int ans = 0;

    for (size_t i = 1; i <= N; i++)
        cache[0][i] = 1;

    for (size_t k = 1; k <= K; k++)
    {
        for (size_t n = 1; n <= N; n++)
        {
            cache[k][n] += cache[0][n];
            for (int &next : tree[n])
            {
                for (int i = 1; i <= k; i++)
                {
                    if (i % 2 == 1)
                        cache[k][n] += cache[k - i][next];
                    else
                        cache[k][n] -= cache[k - i][n];
                }
            }
        }
    }

    for (size_t i = 1; i <= N; i++)
        ans = max(cache[K][i], ans);

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (size_t i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    cout << calculate() << '\n';
}