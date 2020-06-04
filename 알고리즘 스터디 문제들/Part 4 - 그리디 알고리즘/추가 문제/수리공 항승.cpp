#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬하는 풀이법
int main()
{
    size_t N, L;
    cin >> N >> L;

    vector<int> P(N);
    for (size_t i = 0; i < N; i++)
        cin >> P[i];

    int cnt = 0;
    int cur = 0;
    sort(P.begin(), P.end());
    for (size_t i = 0; i < N; i++)
    {
        if (cur <= P[i])
        {
            cnt++;
            cur = P[i] + L;
        }
    }
    cout << cnt;
}

// 정렬없는 풀이법
/*

#include <iostream>
#include <array>
using namespace std;

array<bool, 1000 + 1> P = {};

int main()
{
    size_t N, L;
    cin >> N >> L;

    int input;
    for (size_t i = 0; i < N; i++)
    {
        cin >> input;
        P[input] = true;
    }

    int cnt = 0;
    for (size_t cur = 1; cur <= 1000; cur++)
    {
        if (P[cur])
        {
            cnt++;
            for (size_t i = 1; i <= L; i++)
            {
                P[cur] = false;
                if (i != L)
                    cur++;
            }
        }
    }
    cout << cnt;
}

*/