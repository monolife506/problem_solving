#include <bits/stdc++.h>
using namespace std;

int a[2501], cache[2501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> a[i];

    for (int i = 2; i <= N; ++i)
    {
        cache[i] = cache[i - 1];
        for (int j = i - 1, r_val = a[i]; j > 0; --j)
        {
            r_val = a[j] - r_val;

            if (r_val < 0)
                break;

            if (r_val == 0)
                cache[i] = max(cache[i], cache[j - 1] + 1);
        }
    }

    cout << N - cache[N] << '\n';
}

/*

a b c 100 ...
0 (b - a) c 100 ...

a < b < c
100 - c
100 - (c - b)
100 - (c - b + a)

*/