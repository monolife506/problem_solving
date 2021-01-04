#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const ll MAX = 5000000;

ll prime[MAX + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prime[0] = prime[1] = 1;
    for (size_t i = 2; i <= MAX; i++) {
        if (prime[i] == 1)
            continue;
        for (size_t j = i * 2; j <= MAX; j += i)
            prime[j] = 1;
    }

    ll N, scoreA = 0, scoreB = 0;
    priority_queue<ll, vector<ll>, greater<ll>> primeA;
    priority_queue<ll, vector<ll>, greater<ll>> primeB;

    cin >> N;
    for (size_t i = 0; i < N; i++) {
        ll A, B;
        cin >> A >> B;

        if (prime[A] == 0) {
            if (primeA.size() < 3)
                primeA.push(A);
            else if (primeA.top() < A) {
                primeA.pop();
                primeA.push(A);
            }
            prime[A] = -1;
        } else if (prime[A] == 1) {
            if (primeB.size() < 3)
                scoreB += 1000;
            else
                scoreB += primeB.top();
        } else {
            scoreA -= 1000;
        }

        if (prime[B] == 0) {
            if (primeB.size() < 3)
                primeB.push(B);
            else if (primeB.top() < B) {
                primeB.pop();
                primeB.push(B);
            }
            prime[B] = -1;
        } else if (prime[B] == 1) {
            if (primeA.size() < 3)
                scoreA += 1000;
            else
                scoreA += primeA.top();
        } else {
            scoreB -= 1000;
        }
    }

    if (scoreA == scoreB)
        cout << "우열을 가릴 수 없음";
    else if (scoreA > scoreB)
        cout << "소수의 신 갓대웅";
    else
        cout << "소수 마스터 갓규성";
}