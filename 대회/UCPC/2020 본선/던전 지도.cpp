#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;

ll ans = 0;
ll N, M, K;
string map;
string piece[26];

ll lastU[26][200000]; // Ucnt[i][j] == i번째 조각에서 j번째 글자에서 마지막 U의 위치

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(lastU, -1, sizeof(lastU));

    cin >> N >> M >> K;
    for (size_t i = 0; i < K; i++)
    {
        cin >> piece[i];
        for (int j = 0; j < piece[i].size(); j++)
        {
            lastU[i][j] = ((j == 0) ? -1 : lastU[i][j - 1]);
            if (piece[i][j] == 'U')
                lastU[i][j] = j;
        }
    }
    cin >> map;

    // 가장 윗칸
    int lo, hi; // U가 위치할 수 있는 구간의 시작과 끝
    int curRow = map[N - 1] - 'A';

    if (piece[curRow][M - 1] == 'U' && M >= 2)
    {
        ans += (lastU[curRow][M - 1] - lastU[curRow][M - 2]);
        lo = lastU[curRow][M - 2] + 1;
    }
    else if (M >= 2)
    {
        ans += ((M - 1) - lastU[curRow][M - 1]);
        lo = lastU[curRow][M - 1] + 1;
    }
    else
    {
        ans += 1;
        lo = 0;
    }
    hi = M - 1;

    // 나머지
    for (int i = N - 2; i >= 0; i--)
    {
        curRow = map[i] - 'A';
        if (lastU[curRow][hi] == -1)
            break;

        if (lo == 0)
            ans += (lastU[curRow][hi] + 1);
        else
        {
            ans += (lastU[curRow][hi] - lastU[curRow][lo - 1]);
            lo = lastU[curRow][lo - 1] + 1;
        }
        hi = lastU[curRow][hi];
    }
    cout << ans;
}