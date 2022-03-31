#include <iostream>
using namespace std;
const int MAX = 1000000;

int N;
char pat[MAX];
char str[MAX * 2];

int fail[MAX + 1];

void init()
{
    for (size_t i = 1, j = 0; i < N; i++) {
        while (j > 0 && pat[i] != pat[j])
            j = fail[j - 1];
        if (pat[i] == pat[j])
            fail[i] = ++j;
    }
}

int kmp()
{
    int cnt = 0;
    for (size_t i = 0, j = 0; i < N * 2; i++) {
        while (j > 0 && str[i] != pat[j])
            j = fail[j - 1];
        if (str[i] == pat[j]) {
            if (j == N - 1) // 패턴 일치
            {
                if (i != N * 2 - 1)
                    cnt++;
                j = fail[j];
                continue;
            }
            j++;
        }
    }
    return cnt;
}

int gcd(int A, int B)
{
    int tmp;
    while (B != 0) {
        tmp = A % B;
        A = B;
        B = tmp;
    }
    return A;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> pat[i];
    for (size_t i = 0; i < N; i++) {
        cin >> str[i];
        str[i + N] = str[i];
    }

    init();

    int M = kmp();
    int K = gcd(N, M);
    cout << M / K << '/' << N / K;
}

// BAABAABAABAA
// AABAAB