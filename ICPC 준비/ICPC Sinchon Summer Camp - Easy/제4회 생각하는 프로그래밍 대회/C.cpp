#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

P nums[50];

ll gcd(ll A, ll B) {
    ll N;
    while (B != 0) {
        N = A % B;
        A = B;
        B = N;
    }
    return A;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N >> nums[0].first >> nums[0].second;

    for (size_t i = 1; i < N; i++)
    {
        ll divide = gcd(nums[i - 1].first, nums[i - 1].second);
        nums[i - 1].first /= divide;
        nums[i - 1].second /= divide;

        cin >> nums[i].first >> nums[i].second;

        ll A = nums[i - 1].first * nums[i].second;
        ll B = nums[i].first * nums[i - 1].second;
        
        nums[i].first = gcd(A, B);
        nums[i].second = nums[i].second * nums[i - 1].second;
    }

    ll divide = gcd(nums[N - 1].first, nums[N - 1].second);
    nums[N - 1].first /= divide;
    nums[N - 1].second /= divide;

    cout << nums[N - 1].first << " " << nums[N - 1].second;
}

// 1 3
// 5 2

// 2 15
// 1 6

// 1 6
// 3 4

// 4 18
// 2 24