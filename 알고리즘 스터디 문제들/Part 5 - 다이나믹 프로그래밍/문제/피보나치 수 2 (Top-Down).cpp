#include <iostream>
#include <array>
using namespace std;

// long long을 ll로 표현한다.
typedef long long ll;
array<ll, 91> memo; // memo[i] = i번째 피보나치 수

ll fibo(int N)
{
    if (memo[N] == -1)
    {
        if (N == 0)
            return 0;
        else if (N == 1)
            return 1;

        memo[N] = fibo(N - 1) + fibo(N - 2);
    }

    return memo[N];
}

int main()
{
    // memo 배열을 -1로 초기화시킨다.
    // memo[i] = -1이면 그 결과가 저장되지 않았다는 의미이다.
    memo.fill(-1);

    size_t N;
    cin >> N;
    cout << fibo(N);
}