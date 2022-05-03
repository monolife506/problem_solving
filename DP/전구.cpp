#include <iostream>
using namespace std;

const int INF = 987654321;
int bulb[200], cache[200][200];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 200 * 200, INF);

    size_t N, K;
    cin >> N >> K;
    for (size_t i = 0; i < N; ++i)
    {
        cin >> bulb[i];
        cache[i][i] = 0;
    }

    for (size_t gap = 1; gap < N; ++gap)
    {
        for (size_t i = 0; i < N; ++i)
        {
            if (i + gap >= N)
                continue;

            size_t j = i + gap;
            for (size_t k = i; k < j; ++k)
                cache[i][j] = min(cache[i][j], cache[i][k] + cache[k + 1][j] + (bulb[i] != bulb[k + 1]));
        }
    }

    cout << cache[0][N - 1] << '\n';
}

/*

1 2 3 2 1 3 2 3 1
1 2 2 2 1 3 2 3 1
1 2 2 2 1 3 3 3 1
1 1 1 1 1 3 3 3 1
1 1 1 1 1 1 1 1 1

*/