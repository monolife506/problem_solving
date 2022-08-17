#include <algorithm>
#include <iostream>
using namespace std;

int A[2000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    sort(A, A + N);

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        int lo = 0;
        int hi = N - 1;
        bool flag = false;

        while (lo < hi)
        {
            if (lo == i)
                ++lo;
            if (hi == i)
                --hi;
            if (lo >= hi)
                break;

            if (A[lo] + A[hi] == A[i])
            {
                flag = true;
                break;
            }

            if (A[lo] + A[hi] < A[i])
                ++lo;
            else
                --hi;
        }

        ans += flag;
    }

    cout << ans << '\n';
}

/*

2
0 1


*/