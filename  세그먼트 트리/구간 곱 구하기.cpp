#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

ll arr[1000001];
ll tree[1 << 21]; // height(H) <= H * 4

ll init(int cur, int start, int end)
{
    if (start == end)
        return tree[cur] = arr[start];

    int mid = (start + end) / 2;
    ll left_product = init(cur * 2, start, mid);
    ll right_product = init(cur * 2 + 1, mid + 1, end);
    return tree[cur] = ((left_product % MOD) * (right_product % MOD)) % MOD;
}

ll product(int cur, int start, int end, int L, int R)
{
    if (L > end || R < start)
        return 1;
    if (L <= start && end <= R)
        return tree[cur];

    int mid = (start + end) / 2;
    ll left_product = product(cur * 2, start, mid, L, R);
    ll right_product = product(cur * 2 + 1, mid + 1, end, L, R);
    return ((left_product % MOD) * (right_product % MOD)) % MOD;
}

ll update(int cur, int start, int end, int idx, ll newVal)
{
    if (idx < start || idx > end)
        return tree[cur];

    if (start == end)
        return tree[cur] = newVal;

    int mid = (start + end) / 2;
    ll left_product = update(cur * 2, start, mid, idx, newVal);
    ll right_product = update(cur * 2 + 1, mid + 1, end, idx, newVal);
    return tree[cur] = ((left_product % MOD) * (right_product % MOD)) % MOD;
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
            update(1, 0, N - 1, b - 1, c);
            arr[b - 1] = c;
        } else {
            cout << product(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
    }
}