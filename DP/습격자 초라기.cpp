#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000;
const int INF = 987654321;

int N, W;
int enemy_cnt[2][MAX_N];

// i: 0 == 결합 없음, 1 == 위쪽 결합, 2 == 아래쪽 결합, 3 == 양쪽 결합, 4 == 위아래 결합
int cache[5][MAX_N];

int calculate()
{
    int ret = INF;

    // cache 초기화
    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < N; j++)
            cache[i][j] = INF;

    // circle: 0 == 원형 결합 없음, 1 == 원형 위쪽 결합, 2 == 원형 아래쪽 결합, 3 == 원형 양쪽 결합
    for (size_t circle = 0; circle < 4; circle++)
    {
        cache[circle][0] = 2;

        if ((circle == 1 || circle == 3) && enemy_cnt[1][0] + enemy_cnt[1][N - 1] > W)
            continue;
        if ((circle == 2 || circle == 3) && enemy_cnt[0][0] + enemy_cnt[0][N - 1] > W)
            continue;
        if (circle == 0 && enemy_cnt[0][0] + enemy_cnt[1][0] <= W)
            cache[4][0] = 1;

        for (size_t i = 1; i < N; i++)
        {
            for (size_t j = 0; j < 5; j++)
            {
                if (cache[i][j - 1] == INF)
                    continue;

                bool flag1 = enemy_cnt[1][i] + enemy_cnt[1][i - 1] <= W;
                bool flag2 = enemy_cnt[0][i] + enemy_cnt[0][i - 1] <= W;
                bool flag3 = enemy_cnt[0][i] + enemy_cnt[1][i] <= W;

                cache[0][i] = min(cache[0][i], cache[j][i - 1] + 2);
                if ((j == 0 || j == 2) && flag1)
                    cache[1][i] = min(cache[1][i], cache[j][i - 1] + 1);
                if ((j == 0 || j == 1) && flag2)
                    cache[2][i] = min(cache[2][i], cache[j][i - 1] + 1);
                if (j == 0 && flag1 && flag2)
                    cache[3][i] = min(cache[3][i], cache[j][i - 1]);
                if (flag3)
                    cache[4][i] = min(cache[4][i], cache[j][i - 1] + 1);
            }
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

/* 



*/