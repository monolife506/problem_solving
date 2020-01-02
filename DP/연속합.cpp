// 1912번: 연속합

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<int, 100'000> nums;
array<int, 100'000> max_sum;

int main()
{
    size_t N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    int sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        sum += nums[i];
        max_sum[i] = (sum > nums[i]) ? sum : nums[i];
        sum = max_sum[i];
    }

    cout << *(max_element(max_sum.begin(), max_sum.begin() + N));
}