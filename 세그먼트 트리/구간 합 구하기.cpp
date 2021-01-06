#include <iostream>
using namespace std;
typedef long long ll;

ll arr[1000001];
ll tree[1 << 21]; // height(H) <= H * 4

ll init(int cur, int start, int end)
{
    if (start == end)
        return tree[cur] = arr[start];

    int mid = (start + end) / 2;
    ll left_sum = init(cur * 2, start, mid);
    ll right_sum = init(cur * 2 + 1, mid + 1, end);
    return tree[cur] = left_sum + right_sum;
}

ll sum(int cur, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return 0;
    if (left <= start && end <= right)
        return tree[cur];

    int mid = (start + end) / 2;
    ll left_sum = sum(cur * 2, start, mid, left, right);
    ll right_sum = sum(cur * 2 + 1, mid + 1, end, left, right);
    return left_sum + right_sum;
}

void update(int cur, int start, int end, int idx, ll diff)
{
    if (idx < start || idx > end)
        return;

    tree[cur] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(cur * 2, start, mid, idx, diff);
        update(cur * 2 + 1, mid + 1, end, idx, diff);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, M, K;
    cin >> N >> M >> K;
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    init(1, 0, N - 1);
    for (size_t i = 0; i < M + K; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, N - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        } else {
            cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
}