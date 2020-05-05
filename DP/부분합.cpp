// 1806번: 부분합
// Prefix Sum
// 투 포인터 알고리즘

#include <iostream>
#include <array>
using namespace std;
typedef unsigned long long ll;

array<ll, 100000 + 1> sum;

int main()
{
    int N;
    ll tmp, S;
    cin >> N >> S;

    sum[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        sum[i] = tmp + sum[i - 1];
    }

    int ans = 100001;
    int left = 1;
    int right = 1;
    while (left <= right && left <= N)
    {
        tmp = sum[right - 1] - sum[left - 1];
        if (tmp >= S)
        {
            if (ans > right - left)
                ans = right - left;
            left++;
        }
        else if (right == N + 1)
            break;
        else
            right++;
    }

    if (ans == 100001)
        ans = 0;
    cout << ans;
}