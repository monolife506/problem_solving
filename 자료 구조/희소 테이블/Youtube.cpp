#include <cstring>
#include <iostream>
using namespace std;

const int MAX_N = 100000;
const int MAX_K = 100000;
const int MAX_LOG_M = 30;

int start[MAX_N];
int table[MAX_LOG_M + 1][MAX_K + 1];

int query(int cur, int m)
{
    for (int i = MAX_LOG_M; i >= 0; i--)
    {
        if (m >= (1 << i))
        {
            m -= (1 << i);
            cur = table[i][cur];
        }
    }

    return cur;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(table, -1, sizeof(table));

    int N, K, M;
    cin >> N >> K >> M;
    for (size_t i = 0; i < N; i++)
        cin >> start[i];
    for (size_t i = 1; i <= K; i++)
        cin >> table[0][i];

    // 전처리
    for (size_t i = 1; i <= MAX_LOG_M; i++)
        for (size_t j = 1; j <= K; j++)
            table[i][j] = table[i - 1][table[i - 1][j]];

    // 쿼리
    for (size_t i = 0; i < N; i++)
        cout << query(start[i], M - 1) << " ";

    cout << '\n';
}