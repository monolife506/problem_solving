#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int nums[40];

void calculate(vector<int>& v, int sum, int idx, int last)
{
    if (idx == last) {
        v.push_back(sum);
        return;
    }

    calculate(v, sum + nums[idx], idx + 1, last);
    calculate(v, sum, idx + 1, last);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, S;
    cin >> N >> S;
    for (size_t i = 0; i < N; i++) {
        cin >> nums[i];
    }

    vector<int> left_sum;
    vector<int> right_sum;
    calculate(left_sum, 0, 0, N / 2);
    calculate(right_sum, 0, N / 2, N);
    sort(right_sum.begin(), right_sum.end());

    ll ans = 0;
    for (int sum : left_sum) {
        auto hi = upper_bound(right_sum.begin(), right_sum.end(), S - sum);
        auto lo = lower_bound(right_sum.begin(), right_sum.end(), S - sum);
        ans += hi - lo;
    }

    if (S == 0)
        ans--;

    cout << ans << '\n';
}