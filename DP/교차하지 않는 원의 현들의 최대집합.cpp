#include <iostream>
using namespace std;

int line[101][101], cache[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
    {
        int u, v;
        cin >> u >> v;
        line[u][v] = line[v][u] = 1;
    }

    for (size_t d = 1; d < 100; ++d)
    {
        for (size_t i = 1; i + d <= 100; ++i)
        {
            for (size_t j = i; j < i + d; ++j)
                cache[i][i + d] = max(cache[i][i + d], cache[i][j] + cache[j][i + d] + line[i][i + d]);
        }
    }

    cout << cache[1][100] << '\n';
}