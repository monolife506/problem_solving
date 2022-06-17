#include <iostream>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

ll cache[500000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int h_max, h_cnt = 0;
    cin >> h_max;

    cache[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        int h;
        cin >> h;

        if (h < h_max)
        {
            cache[i] = cache[i - 1];
            ++h_cnt;
        }
        else // h > h_max
        {
            cache[i] = (cache[i - 1] * (h_cnt + 2)) % MOD;
            h_max = h;
            h_cnt = 0;
        }
    }

    cout << cache[N - 1] << '\n';
}

// 1 -> 1
// 1 4 -> 2
// 1 4 2 -> 2
// 1 4 2 5 -> 6

/*

1 4 2 | 5
1 | 4 2 | 5
1 4 | 2 5
1 | 4 | 2 5

*/