#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];

int idx = 1;
int serial[200001];        // dfs 순회시 노드의 번호
int serial_depth[200001];  // dfs 순회시 노드의 depth
int idx_to_serial[100001]; // serial 내에서 특정 번호의 노드가 처음 나타나는 index
int seg_tree[800001];      // serial_depth에 대한 RMQ 세그먼트 트리

void dfs(int parent, int cur, int depth)
{
    serial[idx] = cur;
    serial_depth[idx] = depth;
    idx_to_serial[cur] = idx++;

    for (int next : tree[cur])
    {
        if (parent == next)
            continue;

        dfs(cur, next, depth + 1);
        serial[idx] = cur;
        serial_depth[idx++] = depth;
    }
}

int init(int cur, int lo, int hi)
{
    if (lo == hi)
        return seg_tree[cur] = lo;

    int mid = (lo + hi) / 2;
    int left = init(cur * 2, lo, mid);
    int right = init(cur * 2 + 1, mid + 1, hi);
    return seg_tree[cur] = (serial_depth[left] < serial_depth[right]) ? left : right;
}

int query(int cur, int lo, int hi, int l, int r)
{
    if (l > hi || r < lo)
        return 0;
    if (l <= lo && r >= hi)
        return seg_tree[cur];

    int mid = (lo + hi) / 2;
    int left = query(cur * 2, lo, mid, l, r);
    int right = query(cur * 2 + 1, mid + 1, hi, l, r);

    return (serial_depth[left] < serial_depth[right]) ? left : right;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, a, b;
    cin >> N;
    for (size_t i = 0; i < N - 1; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // 전처리
    serial_depth[0] = INT32_MAX;
    dfs(-1, 1, 0);
    init(1, 1, idx - 1);

    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        cin >> a >> b;
        int l = idx_to_serial[a];
        int r = idx_to_serial[b];
        if (l > r)
            swap(l, r);

        cout << serial[query(1, 1, idx - 1, l, r)] << '\n';
    }
}

/*
세그먼트 트리를 이용해 LCA 구현하기
*/