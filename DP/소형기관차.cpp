#include <iostream>
using namespace std;

int psum[50001], cache[4][50001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;

    cin >> N;
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    cin >> M;
    for (size_t i = 1; i <= 3; ++i)
    {
        for (size_t j = i * M; j <= N; ++j)
            cache[i][j] = max(cache[i][j - 1], cache[i - 1][j - M] + (psum[j] - psum[j - M]));
    }

    cout << cache[3][N] << '\n';
}