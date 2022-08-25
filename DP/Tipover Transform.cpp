#include <iostream>
using namespace std;

const int INF = 987654321;
int x[300001], h[300001], cache[3][300002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 3 * 300001, INF);

    int N, M = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int A;
        cin >> A;
        if (A > 0)
        {
            ++M;
            x[M] = i;
            h[M] = A;
        }
    }

    if (M == 0)
    {
        cout << N << '\n';
    }
    else
    {
        cache[0][1] = x[1] - 1;
        if (x[1] - h[1] > 0)
            cache[1][1] = x[1] - h[1] - 1;
        cache[2][1] = x[1];

        for (int i = 2; i <= M; ++i)
        {
            cache[0][i] = min(cache[0][i], cache[0][i - 1] + x[i] - x[i - 1] - 1);
            cache[0][i] = min(cache[0][i], cache[1][i - 1] + x[i] - (x[i - 1] - 1) - 1);
            if (x[i - 1] + h[i - 1] < x[i])
                cache[0][i] = min(cache[0][i], cache[2][i - 1] + x[i] - (x[i - 1] + h[i - 1]) - 1);

            if (x[i - 1] < x[i] - h[i])
                cache[1][i] = min(cache[1][i], cache[0][i - 1] + (x[i] - h[i]) - x[i - 1] - 1);
            if (x[i - 1] - 1 < x[i] - h[i])
                cache[1][i] = min(cache[1][i], cache[1][i - 1] + (x[i] - h[i]) - (x[i - 1] - 1) - 1);
            if (x[i - 1] + h[i - 1] < x[i] - h[i])
                cache[1][i] = min(cache[1][i], cache[2][i - 1] + (x[i] - h[i]) - (x[i - 1] + h[i - 1]) - 1);

            cache[2][i] = min(cache[2][i], cache[0][i - 1] + (x[i] + 1) - x[i - 1] - 1);
            cache[2][i] = min(cache[2][i], cache[1][i - 1] + (x[i] + 1) - (x[i - 1] - 1) - 1);
            if (x[i - 1] + h[i - 1] < x[i] + 1)
                cache[2][i] = min(cache[2][i], cache[2][i - 1] + (x[i] + 1) - (x[i - 1] + h[i - 1]) - 1);
        }

        int ans = INF;
        ans = min(ans, cache[0][M] + N - x[M]);
        ans = min(ans, cache[1][M] + N - x[M] + 1);
        if (x[M] + h[M] <= N)
            ans = min(ans, cache[2][M] + N - (x[M] + h[M]));

        cout << ans << '\n';
    }
}

/*

7
2 0 0 2 0 0 3

*/