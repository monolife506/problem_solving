#include <iostream>
using namespace std;
typedef unsigned long long ll;

int S[16];

int main()
{
    int N;
    ll W, coinCnt = 0;
    bool buyFlag = false;
    cin >> N >> W;
    for (size_t i = 0; i < N; i++)
        cin >> S[i];

    S[N] = -1;
    for (size_t i = 0; i < N; i++) {
        if (!buyFlag && S[i] < S[i + 1]) {
            buyFlag = true;
            coinCnt = W / S[i];
            W %= S[i];
        } else if (buyFlag && S[i] > S[i + 1]) {
            buyFlag = false;
            W += coinCnt * S[i];
            coinCnt = 0;
        }
    }
    cout << W;
}

// 저점에서 매수
// 고점에서 팔기