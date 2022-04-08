#include <iostream>
using namespace std;

int psum[100001], cache[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M;
    cin >> N >> M;
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
        if (i >= M)
            cache[i] = psum[i] - psum[i - M];
    }

    int ans = 0;
    for (size_t i = M + 1; i <= N; ++i)
    {
        cache[i] = max(cache[i], cache[i - 1] + psum[i] - psum[i - 1]);
        ans = max(ans, cache[i]);
    }

    cout << ans << '\n';
}