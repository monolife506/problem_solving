#include <algorithm>
#include <iostream>
using namespace std;

int N, value[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (size_t i = 0; i < N; ++i)
        cin >> value[i];

    int lo = 0, hi = N - 1;
    int min_lo, min_hi, min_diff = 2000000000;

    sort(value, value + N);
    while (lo != hi)
    {
        int diff = abs(value[lo] + value[hi]);
        if (diff < min_diff)
        {
            min_diff = diff;
            min_lo = lo;
            min_hi = hi;
        }

        int diff_lo = abs(value[lo + 1] + value[hi]);
        int diff_hi = abs(value[lo] + value[hi - 1]);
        (diff_lo <= diff_hi) ? ++lo : --hi;
    }

    cout << value[min_lo] << " " << value[min_hi] << '\n';
}