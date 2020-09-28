// 1644번: 소수의 연속합

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N, primeCnt, cnt = 0;
    int lo = 0, hi = 0, sum = 0;
    cin >> N;

    // 에라토스테네스의 체로 소수들 구하기
    vector<int> prime;
    vector<bool> isPrime(N + 1, true);
    for (size_t i = 2; i <= sqrt(N); i++)
    {
        if (!isPrime[i])
            continue;

        for (size_t j = i + i; j <= N; j += i)
            isPrime[j] = false;
    }
    for (size_t i = 2; i <= N; i++)
    {
        if (isPrime[i])
            prime.push_back(i);
    }

    // 투 포인터로 경우의 수 구하기
    primeCnt = prime.size();
    while (true)
    {
        if (sum >= N)
            sum -= prime[lo++];
        else if (hi == primeCnt)
            break;
        else
            sum += prime[hi++];

        if (sum == N)
            cnt++;
    }

    cout << cnt;
}