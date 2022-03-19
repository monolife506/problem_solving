#include <iostream>
using namespace std;

int table[6][6] = {{10, 8, 7, 5, 0, 1},
                   {8, 6, 4, 3, 0, 1},
                   {7, 4, 3, 2, 0, 1},
                   {5, 3, 2, 2, 0, 1},
                   {0, 0, 0, 0, 0, 0},
                   {1, 1, 1, 1, 0, 0}};

int N, M, cache[14 * 14 + 1][1 << 14];
char grade[15][15];

int get_grade(int i, int j)
{
    return table[grade[i / M][i % M] - 'A'][grade[j / M][j % M] - 'A'];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> grade[i];

    for (int i = 0; i < N * M; ++i)
    {
        for (int j = 0; j < (1 << M); ++j)
        {
            int row = i / M;
            int col = i % M;

            cache[i + 1][j >> 1] = max(cache[i + 1][j >> 1], cache[i][j]);
            if ((j & 1) == 0)
            {
                if (row != N - 1)
                    cache[i + 1][(j >> 1) | (1 << M - 1)] = max(cache[i + 1][(j >> 1) | (1 << M - 1)], cache[i][j] + get_grade(i, i + M));
                if (col != M - 1 && (j & (1 << 1)) == 0)
                    cache[i + 2][j >> 2] = max(cache[i + 2][j >> 2], cache[i][j] + get_grade(i, i + 1));
            }
        }
    }

    cout << cache[N * M][0] << '\n';
}