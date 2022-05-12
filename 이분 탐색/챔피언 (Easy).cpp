#include <algorithm>
#include <iostream>
using namespace std;

int N, a[200001];
int candidate_cnt, candidate_idx[200001];

bool is_champion(int idx)
{
    if (idx == 1 || a[idx] == a[idx - 1])
        return false;

    int power = a[idx] + (idx - 1);
    for (int i = idx + 1; i <= N; ++i)
    {
        if (power > a[i])
            ++power;
        else
            return false;
    }

    return true;
}

int parametric_search(int l, int r)
{
    int ret = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (is_champion(candidate_idx[mid]))
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
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
        if (a[i] != a[i - 1])
            candidate_idx[++candidate_cnt] = i;
    }

    int ans = parametric_search(1, candidate_cnt);
    if (ans == -1)
    {
        cout << (N == 1 ? 1 : -1) << '\n';
    }
    else
    {
        for (int i = ans; i <= candidate_cnt; ++i)
            cout << candidate_idx[i] << " ";

        cout << '\n';
    }
}