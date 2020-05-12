// 2417번: 정수 제곱근

#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll binarySearch(ll N)
{
    ll left = 0;
    ll right = 2 * (ll)INT32_MAX;
    ll mid, ans, val;

    while (left <= right)
    {
        mid = (left + right) / 2;
        val = mid * mid;
        if (val >= N)
        {
            ans = mid;
            if (mid == 0)
                break;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ans;
}

int main()
{
    ll N;
    cin >> N;
    cout << binarySearch(N);
}