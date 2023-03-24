#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100000;

int N;
int dvd_idx[MAX_N + 1];
int tree[8 * MAX_N + 1];

int init(int cur, int lo, int hi)
{
    if (lo == hi)
        return tree[cur] = (lo <= N);

    int mid = (lo + hi) / 2;
    int left = init(cur * 2, lo, mid);
    int right = init(cur * 2 + 1, mid + 1, hi);
    return tree[cur] = left + right;
}

int query(int cur, int lo, int hi, int L, int R)
{
    if (lo > hi || lo > R || hi < L)
        return 0;
    if (L <= lo && R >= hi)
        return tree[cur];

    int mid = (lo + hi) / 2;
    int left = query(cur * 2, lo, mid, L, R);
    int right = query(cur * 2 + 1, mid + 1, hi, L, R);
    return left + right;
}

int update(int cur, int lo, int hi, int idx, int val)
{
    if (idx < lo || idx > hi)
        return tree[cur];
    if (lo == hi)
        return tree[cur] = val;

    int mid = (lo + hi) / 2;
    int left = update(cur * 2, lo, mid, idx, val);
    int right = update(cur * 2 + 1, mid + 1, hi, idx, val);
    return tree[cur] = left + right;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        int m, top;
        cin >> N >> m;

        init(1, 1, 2 * MAX_N);
        for (int i = 1; i <= N; i++)
            dvd_idx[i] = N - (i - 1);

        top = N;
        for (size_t i = 0; i < m; i++)
        {
            int idx;
            cin >> idx;

            cout << query(1, 1, 2 * MAX_N, dvd_idx[idx], 2 * MAX_N) - 1 << " ";
            update(1, 1, 2 * MAX_N, dvd_idx[idx], 0);
            update(1, 1, 2 * MAX_N, ++top, 1);
            dvd_idx[idx] = top;
        }

        cout << '\n';
    }
}