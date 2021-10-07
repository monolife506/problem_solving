#include <iostream>
using namespace std;
typedef pair<int, int> P;

int arr[100001];
P tree[1 << 18];

P init(int cur, int start, int end)
{
    if (start == end)
        return tree[cur] = P(arr[start], arr[start]);

    P left_P = init(cur * 2, start, (start + end) / 2);
    P right_P = init(cur * 2 + 1, ((start + end) / 2) + 1, end);
    tree[cur].first = max(left_P.first, right_P.first);
    tree[cur].second = min(left_P.second, right_P.second);
    return tree[cur];
}

P find(int cur, int start, int end, int L, int R)
{
    if (L > end || R < start)
        return P(0, 1'000'000'001);
    if (L <= start && end <= R)
        return tree[cur];

    P left_P = find(cur * 2, start, (start + end) / 2, L, R);
    P right_P = find(cur * 2 + 1, ((start + end) / 2) + 1, end, L, R);
    return P(max(left_P.first, right_P.first), min(left_P.second, right_P.second));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    init(1, 0, N - 1);
    for (size_t i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        P ans = find(1, 0, N - 1, a - 1, b - 1);
        cout << ans.second << " " << ans.first << '\n';
    }
}