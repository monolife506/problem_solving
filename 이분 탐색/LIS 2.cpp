// 12015번: 가장 긴 증가하는 부분 수열 2
// 12738번: 가장 긴 증가하는 부분 수열 3
// 14003번: 가장 긴 증가하는 부분 수열 5

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    size_t N;
    cin >> N;

    vector<int> LIS(1, INT32_MIN);
    vector<int> nums(1, 0);
    vector<int> pos(1, 0);
    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);

        if (num > LIS.back())
        {
            LIS.push_back(num);
            pos.push_back(LIS.size() - 1);
        }
        else
        {
            int idx = (int)(lower_bound(LIS.begin(), LIS.end(), num) - LIS.begin());
            LIS[idx] = num;
            pos.push_back(idx);
        }
    }

    stack<int> seq;
    int cur = LIS.size() - 1;

    cout << cur << '\n';
    for (size_t i = pos.size() - 1; i > 0; i--)
    {
        if (pos[i] == cur)
        {
            seq.push(nums[i]);
            cur--;
            if (cur == 0)
                break;
        }
    }
    while (!seq.empty())
    {
        cout << seq.top() << " ";
        seq.pop();
    }
}

// 9 40 24 27 61 100 58 59 60 61

// 9
// 9 40
// 9 24
// 9 24 27
// 9 24 27 61
// 9 24 27 61 100
// 9 24 27 58 100
// 9 24 27 58 59
// 9 24 27 58 59 60
// 9 24 27 58 59 60 61