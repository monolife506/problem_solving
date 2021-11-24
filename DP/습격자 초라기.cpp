#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000;
const int INF = 987654321;

int N, W;
int enemy_cnt[2][MAX_N];

// i: 0 == 결합 없음, 1 == 위쪽 결합, 2 == 아래쪽 결합, 3 == 양쪽 결합, 4 == 위아래 결합
int cache[4][5][MAX_N];

int calculate()
{
    int ret = INF;

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 5; j++)
            for (size_t k = 0; k < N; k++)
                cache[i][j][k] = INF;

    for (size_t k = 0; k < 4; k++)
    {
        // 첫 항 초기화
        if (k == 0)
        {
            cache[k][0][0] = 2;
            if (enemy_cnt[0][0] + enemy_cnt[1][0] <= W)
                cache[k][4][0] = 1;
        }
        else
        {
            if (N == 1)
                continue;
            if ((k == 1 || k == 3) && enemy_cnt[0][0] + enemy_cnt[0][N - 1] > W)
                continue;
            if ((k == 2 || k == 3) && enemy_cnt[1][0] + enemy_cnt[1][N - 1] > W)
                continue;
            cache[k][k][0] = 2;
        }

        // DP
        for (size_t i = 1; i < N; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                bool flag1 = (enemy_cnt[0][i] + enemy_cnt[0][i - 1] <= W);
                bool flag2 = (enemy_cnt[1][i] + enemy_cnt[1][i - 1] <= W);
                bool flag4 = (enemy_cnt[0][i] + enemy_cnt[1][i] <= W);

                cache[k][0][i] = min(cache[k][0][i], cache[k][j][i - 1] + 2);
                if ((j == 0 || j == 2) && flag1)
                    cache[k][1][i] = min(cache[k][1][i], cache[k][j][i - 1] + 1);
                if ((j == 0 || j == 1) && flag2)
                    cache[k][2][i] = min(cache[k][2][i], cache[k][j][i - 1] + 1);
                if (j == 0 && flag1 && flag2)
                    cache[k][3][i] = min(cache[k][3][i], cache[k][j][i - 1]);
                if (flag4)
                    cache[k][4][i] = min(cache[k][4][i], cache[k][j][i - 1] + 1);
            }
        }

        // 정답이 될 수 있는 후보값들에 대해 최솟값 갱신
        if (k == 0)
        {
            for (size_t i = 0; i < 5; i++)
                ret = min(ret, cache[k][i][N - 1]);
        }
        else if (k == 1)
        {
            ret = min(ret, min(cache[k][0][N - 1], cache[k][2][N - 1]) - 1);
        }
        else if (k == 2)
        {
            ret = min(ret, min(cache[k][0][N - 1], cache[k][1][N - 1]) - 1);
        }
        else // k == 3
        {
            for (size_t i = 0; i < 5; i++)
                ret = min(ret, cache[k][i][N - 2]);
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        cin >> N >> W;
        for (size_t i = 0; i <= 1; i++)
            for (size_t j = 0; j < N; j++)
                cin >> enemy_cnt[i][j];

        cout << calculate() << '\n';
    }
}