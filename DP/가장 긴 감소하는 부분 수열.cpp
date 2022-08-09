#include <iostream>
using namespace std;

int A[1000], cache[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    for (int i = 0; i < N; ++i)
    {
        cache[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (A[i] < A[j])
                cache[i] = max(cache[i], cache[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans = max(ans, cache[i]);

    cout << ans << '\n';
}