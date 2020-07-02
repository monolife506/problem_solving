// 2098번: 외판원 순회
// https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm

#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100000000;

int N, ans = MAX;
int W[16][16];       // 이동에 드는 비용
int DP[16][1 << 16]; // DP[x][S] = 집합 S의 도시들을 모두 탐색하고 현재 x에 있을 때의 비용

int TSP(int cur, int bitmask)
{
    if (DP[cur][bitmask] != -1) // DP
        return DP[cur][bitmask];

    if (bitmask == 0) // Base case
    {
        if (W[0][cur] != 0)
            return W[0][cur];
        else
            return MAX;
    }

    DP[cur][bitmask] = MAX;
    for (size_t before = 0; before < N; before++)
    {
        if (W[before][cur] == 0 || !(bitmask & (1 << before)))
            continue;

        int beforeSet = (bitmask & ~(1 << before));
        DP[cur][bitmask] = min(DP[cur][bitmask], TSP(before, beforeSet) + W[before][cur]);
    }

    return DP[cur][bitmask];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> W[i][j];
        }
    }
    memset(DP, -1, sizeof(DP)); // -1로 초기화
    cout << TSP(0, ((1 << N) - 2));
}