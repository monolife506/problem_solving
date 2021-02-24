#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> nums(N);
    vector<int> seq;
    vector<int> idx;

    for (int &num : nums)
    {
        cin >> num;

        if (seq.empty() || seq.back() < num)
        {
            seq.push_back(num);
            idx.push_back(seq.size() - 1);
        }
        else
        {
            auto it = lower_bound(seq.begin(), seq.end(), num);
            idx.push_back((int)(it - seq.begin()));
            *it = num;
        }
    }

    int cur = seq.size() - 1;
    stack<int> LIS;

    for (int i = idx.size() - 1; i >= 0; i--)
    {
        if (idx[i] == cur)
        {
            LIS.push(nums[i]);
            cur--;
        }
    }

    cout << seq.size() << '\n';
    while (!LIS.empty())
    {
        cout << LIS.top() << " ";
        LIS.pop();
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