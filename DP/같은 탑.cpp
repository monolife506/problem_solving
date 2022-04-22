#include <iostream>
using namespace std;

int h[50], cache[51][500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 51 * 500001, -500001);

    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> h[i];

    cache[0][0] = 0;
    for (int i = 0; i < N; ++i) // nth
    {
        for (int j = 0; j <= 500000; ++j) // diff
        {
            cache[i + 1][j] = max(cache[i + 1][j], cache[i][j]);

            if (j + h[i] <= 500000)
                cache[i + 1][j + h[i]] = max(cache[i + 1][j + h[i]], cache[i][j] + h[i]);
            if (j >= h[i])
                cache[i + 1][j - h[i]] = max(cache[i + 1][j - h[i]], cache[i][j]);
            else
                cache[i + 1][h[i] - j] = max(cache[i + 1][h[i] - j], cache[i][j] + (h[i] - j));
        }
    }

    cout << (cache[N][0] != 0 ? cache[N][0] : -1) << '\n';
}