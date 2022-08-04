#include <cstring>
#include <iostream>
using namespace std;

int A[100000], cache[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    int ans = 1;
    for (int d = -100; d <= 100; ++d)
    {
        memset(cache, 0, sizeof(cache));
        for (int i = 0; i < N; ++i)
        {
            if (A[i] - d > 0 && A[i] - d <= 100)
                cache[A[i]] = cache[A[i] - d] + 1;
            else
                cache[A[i]] = 1;

            ans = max(ans, cache[A[i]]);
        }
    }

    cout << ans << '\n';
}

/*

5
1 3 3 3 5
3

2
24 100

*/