#include <iostream>
using namespace std;
typedef long long ll;

int A[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        A[i] %= 2;
    }

    ll cnt[2] = {};

    int tmp = 0;
    for (int i = 0; i < N; ++i)
    {
        if (A[i] == 0)
            ++tmp;
        else
            cnt[0] += tmp;
    }

    tmp = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if (A[i] == 0)
            ++tmp;
        else
            cnt[1] += tmp;
    }

    cout << min(cnt[0], cnt[1]) << '\n';
}

/*

0 1 1 0
0 1 0 1
0 0 1 1

1 0 1 1
0 1 1 1

01 or 10

0 1 0 1 0
1 0 0 1 0

*/