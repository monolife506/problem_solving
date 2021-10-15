#include <iostream>
using namespace std;

const int MAX = 1'000'000'000 + 1;

int arr[100001];
int tree[400001];

int init(int cur, int lo, int hi)
{
    if (lo == hi)
        return tree[cur] = lo;

    int mid = (lo + hi) / 2;
    int left = init(cur * 2, lo, mid);
    int right = init(cur * 2 + 1, mid + 1, hi);
    return tree[cur] = (arr[left] <= arr[right]) ? left : right;
}

int query(int cur, int lo, int hi, int L, int R)
{
    if (L > hi || R < lo)
        return 0;
    if (L <= lo && R >= hi)
        return tree[cur];

    int mid = (lo + hi) / 2;
    int left = query(cur * 2, lo, mid, L, R);
    int right = query(cur * 2 + 1, mid + 1, hi, L, R);
    return (arr[left] <= arr[right]) ? left : right;
}

int update(int cur, int lo, int hi, int idx)
{
    if (idx < lo || idx > hi || lo == hi)
        return tree[cur];

    int mid = (lo + hi) / 2;
    int left = update(cur * 2, lo, mid, idx);
    int right = update(cur * 2 + 1, mid + 1, hi, idx);
    return tree[cur] = (arr[left] <= arr[right]) ? left : right;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N;

    arr[0] = MAX;
    for (size_t i = 1; i <= N; i++)
        cin >> arr[i];

    init(1, 1, N);

    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        int q, a, b;
        cin >> q >> a >> b;

        if (q == 1)
        {
            arr[a] = b;
            update(1, 1, N, a);
        }
        else
        {
            cout << query(1, 1, N, a, b) << '\n';
        }
    }
}