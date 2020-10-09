#include <iostream>
using namespace std;

int N, K;
int pi[100];   // 나가는 순서
int gate[101]; // i번 게이트에 서있는 맨 뒤 사람 (0 == 없음)

int main()
{
    cin >> N >> K;
    for (size_t i = 0; i < N; i++)
        cin >> pi[i];

    for (size_t i = 0; i < N; i++)
    {
        int gatenum = 0;
        for (size_t j = 1; j <= K; j++)
        {
            if (gate[j] == 0 || (gate[j] < pi[i] && gate[gatenum] < gate[j]))
                gatenum = j;
        }

        if (gatenum == 0)
        {
            cout << "NO";
            return 0;
        }

        gate[gatenum] = pi[i];
    }

    cout << "YES";
}

// 4 5 6 8 9 10
// 1 3 7
// 2