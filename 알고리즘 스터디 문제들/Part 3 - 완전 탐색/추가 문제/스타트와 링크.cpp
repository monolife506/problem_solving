#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// S[i][j] == (i + 1), (j + 1)번 사람이 팀에 있을 때 추가 능력치
array<array<int, 20>, 20> S;

int main()
{
    size_t N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            cin >> S[i][j];
    }

    vector<bool> sel(N, 0);
    for (size_t i = 0; i < N / 2; i++)
        sel[i] = 1;

    int start;
    int link;
    int min_diff = INT32_MAX;
    do
    {
        start = 0;
        link = 0;

        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (sel[i] && sel[j])
                    start += S[i][j];
                else if (!sel[i] && !sel[j])
                    link += S[i][j];
            }
        }

        if (min_diff > abs(start - link))
            min_diff = abs(start - link);
    } while (prev_permutation(sel.begin(), sel.end()));

    cout << min_diff;
}