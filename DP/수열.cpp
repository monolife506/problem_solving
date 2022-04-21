#include <iostream>
using namespace std;

const int MAX_N = 1e5;

int psum[MAX_N + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, K;
    cin >> N >> K;
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    int ans = INT32_MIN;
    for (size_t i = K; i <= N; ++i)
        ans = max(ans, psum[i] - psum[i - K]);

    cout << ans << '\n';
}