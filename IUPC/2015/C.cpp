#include <iostream>
using namespace std;

bool S[100001];
bool xS[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    for (size_t i = 1; i <= N; i++)
        cin >> S[i];

    xS[0] = 0;
    for (size_t i = 1; i <= N; i++)
        xS[i] = S[i - 1] ^ S[i];

    int ans = 0;
    for (size_t i = 1; i <= N - K + 2; i++) {
        if (xS[i]) {
            xS[i] ^= 1;
            xS[i + K] ^= 1;
            ++ans;
        }
    }

    for (size_t i = N - K + 2; i <= N; i++) {
        if (xS[i]) {
            cout << "Insomnia";
            return 0;
        }
    }

    cout << ans;
}

// XOO
// XXX

// XOX
// XXO

// OXO
// XOO
// XXX

// OOXXXO
// XXOXXO
// XXXOOO
// XXXXXX
