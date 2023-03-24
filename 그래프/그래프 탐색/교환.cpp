#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000000;
typedef pair<int, int> P;

bool visited[11][MAX + 1];

int bfs(int n, int k)
{
    const int ten_pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

    int ret = -1;
    int digit_cnt = 0;

    for (size_t i = 1; i < 8; i++)
        if (n >= ten_pow[i])
            digit_cnt++;

    queue<P> q;
    q.push({n, 0});
    visited[0][n] = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for (size_t i = 0; i < digit_cnt; i++)
        {
            for (size_t j = i + 1; j <= digit_cnt; j++)
            {
                int i_digit = (cur % ten_pow[i + 1]) / ten_pow[i];
                int j_digit = (cur % ten_pow[j + 1]) / ten_pow[j];
                if (j == digit_cnt && i_digit == 0)
                    continue;

                int nxt_num = cur - (i_digit * ten_pow[i]) + (j_digit * ten_pow[i]) - (j_digit * ten_pow[j]) + (i_digit * ten_pow[j]);
                if (!visited[cnt + 1][nxt_num])
                {
                    visited[cnt + 1][nxt_num] = true;
                    if (cnt == k - 1)
                        ret = max(ret, nxt_num);
                    else
                        q.push(P(nxt_num, cnt + 1));
                }
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << '\n';
}