#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

size_t N, M;
int psum[301], cache[301][301], r_size[301][301];

int dp(int cnt, int r)
{
    if (cnt == 1)
        return psum[r];
    if (cache[cnt][r] != -1)
        return cache[cnt][r];

    cache[cnt][r] = INT32_MAX;
    for (size_t i = 1 + (cnt - 2); i < r; ++i)
    {
        int nxt = max(dp(cnt - 1, i), psum[r] - psum[i]);
        if (cache[cnt][r] > nxt)
        {
            cache[cnt][r] = nxt;
            r_size[cnt][r] = r - i;
        }
    }

    return cache[cnt][r];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(cache, -1, sizeof(cache));
    memset(r_size, -1, sizeof(r_size));

    cin >> N >> M;
    for (size_t i = 1; i <= N; ++i)
    {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    cout << dp(M, N) << '\n';

    stack<int> groups;

    int r = N;
    while (M > 1)
    {
        groups.push(r_size[M][r]);
        r -= r_size[M][r];
        --M;
    }

    cout << r << " ";
    while (!groups.empty())
    {
        cout << groups.top() << " ";
        groups.pop();
    }

    cout << '\n';
}