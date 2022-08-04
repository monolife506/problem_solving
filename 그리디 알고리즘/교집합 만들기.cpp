#include <iostream>
#include <map>
using namespace std;

map<pair<int, int>, bool> interval;
map<int, int> interval_left;
map<int, int> interval_right;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int l, r;
        cin >> l >> r;
        interval[{l, r}] = true;

        if (interval_left.find(l) == interval_left.end())
            interval_left[l] = r;
        else
            interval_left[l] = max(interval_left[l], r);

        if (interval_right.find(r) == interval_right.end())
            interval_right[r] = l;
        else
            interval_right[r] = min(interval_right[r], l);
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q)
    {
        int l, r;
        cin >> l >> r;

        if (interval.find({l, r}) != interval.end())
            cout << 1 << '\n';
        else if (interval_left.find(l) != interval_left.end() && interval_right.find(r) != interval_right.end() && interval_left[l] >= r && interval_right[r] <= l)
            cout << 2 << '\n';
        else
            cout << -1 << '\n';
    }
}