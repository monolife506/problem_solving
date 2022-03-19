#include <iostream>
using namespace std;

const int MOD = 9901;

int cache[14 * 14 + 1][1 << 14];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    cache[0][0] = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int k = 0; k < (1 << M); ++k)
            {
                int cur = i * M + j;

                if (k & 1)
                {
                    cache[cur + 1][k >> 1] += cache[cur][k];
                    cache[cur + 1][k >> 1] %= MOD;
                    continue;
                }

                if (i != N - 1)
                {
                    cache[cur + 1][(k >> 1) | (1 << (M - 1))] += cache[cur][k];
                    cache[cur + 1][(k >> 1) | (1 << (M - 1))] %= MOD;
                }
                if (j != M - 1 && (k & (1 << 1)) == 0)
                {
                    cache[cur + 2][k >> 2] += cache[cur][k];
                    cache[cur + 2][k >> 2] %= MOD;
                }
            }
        }
    }

    cout << cache[N * M][0] << '\n';
}

// 나는 빡대가리입니다
