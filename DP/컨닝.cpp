#include <cstring>
#include <iostream>
using namespace std;

const int MAX_N = 10;
const int MAX_M = 10;

int N, M;
int class_map[MAX_N + 1]; // bitset으로 표현된 교실의 상태 ('x' == 1, '.' == 0)
int cache[MAX_N + 1][1 << MAX_M];

int cnt[1 << MAX_M];                      // i가 배치 가능한 형태일 때 학생의 수
bool check_lower[1 << MAX_M][1 << MAX_M]; // i 위에 j를 배치할 수 있는가?

void precomputation()
{
    for (int i = 0; i < (1 << MAX_M); i++)
    {
        cnt[i] = 0;
        for (int j = 0; j < MAX_M; j++)
        {
            if (!(i & (1 << j)))
                continue;

            cnt[i]++;
            if (j - 1 >= 0 && (i & (1 << (j - 1))))
            {
                cnt[i] = -1;
                break;
            }
            if (j + 1 <= MAX_M && (i & (1 << (j + 1))))
            {
                cnt[i] = -1;
                break;
            }
        }
    }

    for (int i = 0; i < (1 << MAX_M); i++)
    {
        for (int j = 0; j < (1 << MAX_M); j++)
        {
            if (cnt[i] == -1 || cnt[j] == -1)
                continue;

            check_lower[i][j] = true;
            for (int k = 0; k < MAX_M; k++)
            {
                if (!(i & (1 << k)))
                    continue;

                if (k - 1 >= 0 && (j & (1 << (k - 1))))
                {
                    check_lower[i][j] = false;
                    break;
                }
                if (k + 1 <= MAX_M && (j & (1 << (k + 1))))
                {
                    check_lower[i][j] = false;
                    break;
                }
            }
        }
    }
}

int solve()
{
    int ret = -1;

    for (size_t i = 0; i < (1 << M); i++)
    {
        if (cnt[i] != -1 && !(i & class_map[N]))
        {
            cache[N][i] = cnt[i];
            ret = max(ret, cache[N][i]);
        }
    }

    for (int i = N - 1; i > 0; i--)
    {
        for (size_t j = 0; j < (1 << M); j++) // 전 행의 배치
        {
            if (cache[i + 1][j] == -1)
                continue;

            for (size_t k = 0; k < (1 << M); k++) // 현재 행의 배치
            {
                if (cnt[k] == -1 || (k & class_map[i]) || !check_lower[j][k])
                    continue;

                cache[i][k] = max(cache[i][k], cache[i + 1][j] + cnt[k]);
                ret = max(ret, cache[i][k]);
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

    precomputation();

    size_t C;
    cin >> C;
    for (size_t tc = 0; tc < C; tc++)
    {
        memset(class_map, 0, sizeof(class_map));
        memset(cache, -1, sizeof(cache));

        cin >> N >> M;
        for (size_t i = 1; i <= N; i++)
        {
            char input[MAX_M + 1];
            cin >> input;
            for (size_t j = 0; j < M; j++)
            {
                if (input[j] == 'x')
                    class_map[i] += (1 << j);
            }
        }

        cout << solve() << '\n';
    }
}