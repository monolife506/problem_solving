// 14888번: 연산자 끼워넣기

#include <iostream>
#include <array>
using namespace std;

size_t N;
array<int, 11> nums;
array<int, 4> cnts; // +, -, *, /
bool flag_max = false;
bool flag_min = false;
int max_num = 0;
int min_num = 0;

void solve(int depth, int res)
{
    if (depth == N)
    {
        if (res > max_num || !flag_max)
        {
            flag_max = true;
            max_num = res;
        }
        if (res < min_num || !flag_min)
        {
            flag_min = true;
            min_num = res;
        }
        return;
    }

    for (size_t i = 0; i < 4; i++)
    {
        if (cnts[i] != 0)
        {
            cnts[i]--;
            switch (i)
            {
            case 0:
                solve(depth + 1, res + nums[depth]);
                break;
            case 1:
                solve(depth + 1, res - nums[depth]);
                break;
            case 2:
                solve(depth + 1, res * nums[depth]);
                break;
            case 3:
                solve(depth + 1, res / nums[depth]);
                break;
            }
            cnts[i]++;
        }
    }
}

int main()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> nums[i];
    for (int &cnt : cnts)
        cin >> cnt;

    solve(1, nums[0]);
    cout << max_num << '\n';
    cout << min_num;
}
