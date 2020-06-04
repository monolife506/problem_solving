#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t N, S, R;
    cin >> N >> S >> R;

    int input;
    vector<int> T(N + 1, 1); // 각 팀의 카약의 개수
    for (size_t i = 0; i < S; i++)
    {
        cin >> input;
        T[input]--;
    }
    for (size_t i = 0; i < R; i++)
    {
        cin >> input;
        T[input]++;
    }

    int cnt = 0;
    for (size_t i = 1; i <= N; i++)
    {
        if (T[i] == 0)
        {
            if (i != 1 && T[i - 1] == 2)
            {
                T[i - 1]--;
                continue;
            }
            else if (i != N && T[i + 1] == 2)
            {
                T[i + 1]--;
                continue;
            }
            cnt++;
        }
    }
    cout << cnt;
}