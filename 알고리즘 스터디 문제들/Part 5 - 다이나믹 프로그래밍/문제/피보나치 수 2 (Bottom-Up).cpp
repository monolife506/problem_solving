#include <iostream>
#include <array>
using namespace std;

// long long을 ll로 표현한다.
typedef long long ll;
array<ll, 91> memo; // memo[i] = i번째 피보나치 수

int main()
{
    // Base Case
    memo[0] = 0;
    memo[1] = 1;

    // 타뷸레이션
    for (size_t i = 2; i < 91; i++)
        memo[i] = memo[i - 1] + memo[i - 2];

    size_t N;
    cin >> N;
    cout << memo[N];
}