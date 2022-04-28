#include <iostream>
using namespace std;

const int INF = 987654321;
int A[2000], B[2000], cache[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 2001 * 2001, -INF);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> A[i];
    for (size_t i = 0; i < N; ++i)
        cin >> B[i];

    cache[0][0] = 0;
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < N; ++j)
        {
            cache[i + 1][j] = max(cache[i + 1][j], cache[i][j]);
            cache[i + 1][j + 1] = max(cache[i + 1][j + 1], cache[i][j]);

            if (A[i] > B[j])
                cache[i][j + 1] = max(cache[i][j + 1], cache[i][j] + B[j]);
        }
    }

    int ans = 0;
    for (size_t i = 0; i < N; ++i)
        ans = max(ans, max(cache[N][i], cache[i][N]));

    ans = max(ans, cache[N][N]);

    cout << ans << '\n';
}