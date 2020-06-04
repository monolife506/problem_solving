// 11054번: 가장 긴 바이토닉 부분 수열

#include <iostream>
#include <array>
using namespace std;

array<int, 1000> nums;
array<array<int, 2>, 1000> cnt{};

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            if (cnt[j][0] < cnt[i][0] + 1 && nums[i] < nums[j])
            {
                cnt[j][0] = cnt[i][0] + 1;
            }
        }
    }

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (cnt[j][1] < cnt[i][1] + 1 && nums[i] < nums[j])
            {
                cnt[j][1] = cnt[i][1] + 1;
            }
        }
    }

    int max_sum{0};
    for (size_t i = 0; i < N; i++)
    {
        if (max_sum < cnt[i][0] + cnt[i][1] + 1)
        {
            max_sum = cnt[i][0] + cnt[i][1] + 1;
        }
    }
    cout << max_sum;
}