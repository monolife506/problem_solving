#include <iostream>
using namespace std;
typedef long long ll;

const ll MAX = 1e9;

int N, T[100000];

bool f(int t)
{
    int cnt = 0, min_cnt = 1;
    for (int i = 0; i < N; ++i)
    {
        if (T[i] <= t)
            ++cnt;
        else
            min_cnt += ((T[i] + t - 1) / t) - 2;
    }

    return cnt >= min_cnt;
}

int parametric_search(int l, int r)
{
    int ret;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (f(mid))
        {
            ret = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> T[i];

    cout << parametric_search(1, MAX) << '\n';
}

/*

11  33333
 2222   44
+*++*+++** -> 0 + 2 + 3 + 0 + 1

11111  33
    222244 -> 3 + 2 + 0 + 0 + 1
++++*++***

11333
 22 444
+**+*+* -> 0 + 0 + 1 + 1 + 1

*/