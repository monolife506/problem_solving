#include <iostream>
#include <array>
using namespace std;

int N;
int max_val = INT32_MIN;
int min_val = INT32_MAX;

array<int, 11> num;
array<int, 4> oper; // 연산자의 개수

void backtrack(int cnt, int total)
{
    if (cnt == N - 1)
    {
        max_val = max(max_val, total);
        min_val = min(min_val, total);
        return;
    }

    if (oper[0] > 0)
    {
        oper[0]--;
        backtrack(cnt + 1, total + num[cnt + 1]);
        oper[0]++;
    }

    if (oper[1] > 0)
    {
        oper[1]--;
        backtrack(cnt + 1, total - num[cnt + 1]);
        oper[1]++;
    }

    if (oper[2] > 0)
    {
        oper[2]--;
        backtrack(cnt + 1, total * num[cnt + 1]);
        oper[2]++;
    }

    if (oper[3] > 0)
    {
        oper[3]--;
        backtrack(cnt + 1, total / num[cnt + 1]);
        oper[3]++;
    }
}

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> num[i];
    for (size_t i = 0; i < 4; i++)
        cin >> oper[i];

    backtrack(0, num[0]);
    cout << max_val << '\n'
         << min_val;
}