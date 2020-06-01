#include <iostream>
#include <array>
using namespace std;

int N;
int min_diff = INT32_MAX;

array<array<int, 20>, 20> stats;
array<bool, 20> choice = {};

void backtrack(int pre, int cnt)
{
    if (cnt == N / 2)
    {
        int start = 0;
        int link = 0;
        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (choice[i] && choice[j])
                    start += stats[i][j];
                else if (!choice[i] && !choice[j])
                    link += stats[i][j];
            }
        }

        min_diff = min(min_diff, abs(start - link));
        return;
    }

    for (size_t i = pre + 1; i < N; i++)
    {
        choice[i] = true;
        backtrack(i, cnt + 1);
        choice[i] = false;
    }
}

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            cin >> stats[i][j];
    }

    backtrack(0, 0);
    cout << min_diff;
}