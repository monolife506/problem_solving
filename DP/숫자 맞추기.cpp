#include <iostream>
#include <stack>
using namespace std;

const int INF = 987654321;
char buffer[10001];
int from[10001], to[10001], cache[10][10001], pre[10][10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0][0], 10 * 10001, INF);

    size_t N;
    cin >> N;

    cin >> buffer;
    for (size_t i = 1; i <= N; ++i)
        from[i] = buffer[i - 1] - '0';

    cin >> buffer;
    for (size_t i = 1; i <= N; ++i)
        to[i] = buffer[i - 1] - '0';

    cache[0][0] = 0;
    cache[(to[1] - from[1] + 10) % 10][1] = (to[1] - from[1] + 10) % 10;
    cache[0][1] = (from[1] - to[1] + 10) % 10;
    pre[(to[1] - from[1] + 10) % 10][0] = pre[0][1] = 0;

    for (size_t i = 2; i <= N; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            int cur = (from[i] + j) % 10;
            int l_cnt = (to[i] - cur + 10) % 10;
            int r_cnt = (cur - to[i] + 10) % 10;

            if (cache[(j + l_cnt) % 10][i] > cache[j][i - 1] + l_cnt)
            {
                cache[(j + l_cnt) % 10][i] = cache[j][i - 1] + l_cnt;
                pre[(j + l_cnt) % 10][i] = j;
            }
            if (cache[j][i] > cache[j][i - 1] + r_cnt)
            {
                cache[j][i] = cache[j][i - 1] + r_cnt;
                pre[j][i] = j;
            }
        }
    }

    int ans = INF, l;
    for (int i = 0; i < 10; ++i)
    {
        if (ans > cache[i][N])
        {
            ans = cache[i][N];
            l = i;
        }
    }

    cout << ans << '\n';

    stack<int> s;
    for (size_t i = N; i > 0; --i)
    {
        if (l != pre[l][i])
            s.push(cache[l][i] - cache[pre[l][i]][i - 1]);
        else
            s.push(cache[pre[l][i]][i - 1] - cache[l][i]);

        l = pre[l][i];
    }
    for (size_t i = 1; i <= N; ++i)
    {
        cout << i << " " << s.top() << '\n';
        s.pop();
    }
}