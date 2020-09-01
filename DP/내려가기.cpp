// 2096번: 내려가기
// 슬라이딩 윈도우 기법

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    int maxdp[2][3];
    int mindp[2][3];

    cin >> N;
    for (size_t i = 0; i < 3; i++)
    {
        cin >> maxdp[0][i];
        mindp[0][i] = maxdp[0][i];
    }
    for (size_t i = 1; i < N; i++)
    {
        bool cur = i % 2;
        for (size_t j = 0; j < 3; j++)
        {
            cin >> maxdp[cur][j];
            mindp[cur][j] = maxdp[cur][j];
        }

        maxdp[cur][0] += max(maxdp[!cur][0], maxdp[!cur][1]);
        mindp[cur][0] += min(mindp[!cur][0], mindp[!cur][1]);
        maxdp[cur][1] += max(maxdp[!cur][0], max(maxdp[!cur][1], maxdp[!cur][2]));
        mindp[cur][1] += min(mindp[!cur][0], min(mindp[!cur][1], mindp[!cur][2]));
        maxdp[cur][2] += max(maxdp[!cur][1], maxdp[!cur][2]);
        mindp[cur][2] += min(mindp[!cur][1], mindp[!cur][2]);
    }

    bool last = (N - 1) % 2;
    cout << max(maxdp[last][0], max(maxdp[last][1], maxdp[last][2])) << " "
         << min(mindp[last][0], min(mindp[last][1], mindp[last][2]));
}