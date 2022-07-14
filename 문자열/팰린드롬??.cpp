#include <iostream>
using namespace std;

int N, M, seq[2000001], p[2000001];

void manacher()
{
    int c = -1, r = -1;
    for (int i = 0; i <= N * 2; ++i)
    {
        if (r < i)
        {
            p[i] = 0;
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 <= 2 * N && seq[i - p[i] - 1] == seq[i + p[i] + 1])
                ++p[i];

            c = i;
            r = i + p[i];
        }
        else
        {
            p[i] = min(r - i, p[c + (c - i)]);
            if (r - i == p[c + (c - i)])
            {
                while (i - p[i] - 1 >= 0 && i + p[i] + 1 <= 2 * N && seq[i - p[i] - 1] == seq[i + p[i] + 1])
                    ++p[i];

                c = i;
                r = i + p[i];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i <= 2 * N; ++i)
    {
        if (i % 2 == 0)
            seq[i] = -1;
        else
            cin >> seq[i];
    }

    manacher();

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int S, E;
        cin >> S >> E;
        cout << (p[S + E - 1] >= E - S) << '\n';
    }
}

/*

| 1 | 2 | 1 | 3 | 1 | 2 | 1 |
0 1 0 3 0 1 0 7 0 1 0 3 0 1 0

| 1 | 2 | 2 | 1 |
0 1 0 1 4 1 0 1 0

*/