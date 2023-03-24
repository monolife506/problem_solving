#include <iostream>
using namespace std;
typedef pair<int, int> P;

struct SegmentTree // 최대/최솟값 세그먼트 트리
{
    P *tree;
    size_t capacity;

    SegmentTree(size_t n)
    {
        capacity = 1;
        while (capacity < n)
            capacity *= 2;

        tree = new P[capacity * 2];
        for (int i = capacity; i < capacity + n; ++i)
            tree[i] = {i - capacity, i - capacity};
        for (int i = capacity + n; i < capacity * 2; ++i)
            tree[i] = {INT32_MAX, INT32_MIN};
        for (int i = capacity - 1; i > 0; --i)
        {
            tree[i].first = min(tree[i * 2].first, tree[i * 2 + 1].first);
            tree[i].second = max(tree[i * 2].second, tree[i * 2 + 1].second);
        }
    }

    ~SegmentTree() { delete[] tree; }

    P query(int L, int R)
    {
        P ret = {INT32_MAX, INT32_MIN};
        for (L += capacity, R += capacity; L < R; L /= 2, R /= 2)
        {
            if (L % 2 == 1)
            {
                ret.first = min(ret.first, tree[L].first);
                ret.second = max(ret.second, tree[L].second);
                ++L;
            }
            if (R % 2 == 0)
            {
                ret.first = min(ret.first, tree[R].first);
                ret.second = max(ret.second, tree[R].second);
                --R;
            }
        }
        if (L == R)
        {
            ret.first = min(ret.first, tree[L].first);
            ret.second = max(ret.second, tree[L].second);
        }

        return ret;
    }

    void update(int idx, int val)
    {
        tree[capacity + idx] = {val, val};
        for (int i = (capacity + idx) / 2; i > 0; i /= 2)
        {
            tree[i].first = min(tree[i * 2].first, tree[i * 2 + 1].first);
            tree[i].second = max(tree[i * 2].second, tree[i * 2 + 1].second);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        size_t N, K;
        cin >> N >> K;

        SegmentTree tree(N);
        for (size_t k = 0; k < K; ++k)
        {
            int Q, A, B;
            cin >> Q >> A >> B;
            if (Q == 0)
            {
                int a_val = tree.query(A, A).first;
                int b_val = tree.query(B, B).first;
                tree.update(A, b_val);
                tree.update(B, a_val);
            }
            else
            {
                P ans = tree.query(A, B);
                cout << (ans.first == A && ans.second == B ? "YES" : "NO") << '\n';
            }
        }
    }
}