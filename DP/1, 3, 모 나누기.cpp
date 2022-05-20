#include <iostream>
using namespace std;
typedef long long ll;

ll a[2001], psum[2001], cache[7][2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
        cache[1][i] = max(psum[i], cache[0][i]);
    }

    for (size_t i = 2; i <= 6; ++i)
    {
        for (size_t r = 1; r <= N; ++r)
        {
            for (size_t l = 1; l <= r; ++l)
            {
                if (i % 2 == 0)
                    cache[i][r] = max(cache[i][r], cache[i - 1][l]);
                else
                    cache[i][r] = max(cache[i][r], cache[i - 1][l] + (psum[r] - psum[l]));
            }
        }
    }

    cout << cache[6][N] << '\n';
}

/*

*/