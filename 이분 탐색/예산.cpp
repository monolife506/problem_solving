#include <iostream>
using namespace std;

int N, M, num[100000];

bool f(int c)
{
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        if (num[i] <= c)
            sum += num[i];
        else
            sum += c;
    }

    return sum <= M;
}

int parametric_search(int l, int r)
{
    int mid, ret;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid))
        {
            ret = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
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

    int r = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> num[i];
        r = max(r, num[i]);
    }

    cin >> M;
    cout << parametric_search(0, r) << '\n';
}