// 1086번: 박성원
// 너무 어렵다..
// 정수론을 더 공부해야 될 것 같다..

#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int N, K;
string nums[15]; // string으로 나타낸 정수 집합

int ten[51];       // ten[i] = (10^i % k)의 값
int numRemain[15]; // numRemain[i] == nums[i] % K;
int len[15];
ll DP[1 << 15][100]; // DP[S][A] == 집합 S의 숫자에 대해 K로 나눴을 때 나머지가 A인 순열의 수

void init()
{
    // ten 초기화
    ten[0] = 1 % K;
    for (size_t i = 1; i <= 50; i++)
        ten[i] = ((10 % K) * ten[i - 1]) % K;

    // reminder 초기화
    for (size_t i = 0; i < N; i++)
    {
        numRemain[i] = 0;
        for (size_t j = 0; j < len[i]; j++)
        {
            numRemain[i] = ((numRemain[i] * (10 % K)) % K) + ((nums[i][j] - '0') % K);
            numRemain[i] %= K;
        }
    }
}

void ans()
{
    DP[0][0] = 1;
    for (size_t i = 0; i < (1 << N); i++) // 현재 집합
    {
        for (size_t j = 0; j < K; j++) // 현재 나머지
        {
            for (size_t k = 0; k < N; k++) // 뒤에 붙일 수
            {
                if (!(i & (1 << k))) // k번째 수가 집합에 없을 때
                {
                    ll remain = ((j * ten[len[k]]) % K) + (numRemain[k] % K);
                    remain %= K;

                    DP[i | (1 << k)][remain] += DP[i][j];
                }
            }
        }
    }
}

ll gcd(ll a, ll b)
{
    if (b != 0)
        return gcd(b, a % b);
    return a;
}

ll fac(int N)
{
    ll ans = 1;
    for (ll i = 2; i <= N; i++)
        ans *= i;

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> nums[i];
        len[i] = nums[i].size();
    }
    cin >> K;

    init();
    ans();

    ll numer = DP[(1 << N) - 1][0];
    ll deno = fac(N);
    if (numer == 0)
    {
        cout << 0 << "/" << 1;
    }
    else
    {
        ll fraction = gcd(deno, numer);

        numer /= fraction;
        deno /= fraction;
        cout << numer << "/" << deno;
    }
}