#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;

struct vector2
{
    int x, y;
    explicit vector2(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const vector2 &rhs) const
    {
        return (x != rhs.x) ? x < rhs.x : y > rhs.y;
    }
};

struct segment_tree
{
    int *tree;
    size_t capacity;

    segment_tree(size_t n)
    {
        capacity = 1;
        while (capacity < n)
            capacity *= 2;

        tree = new int[capacity * 2];
        memset(tree, 0, sizeof(int) * capacity * 2);
    }

    ~segment_tree() { delete[] tree; }

    int sum(int L, int R)
    {
        int ret = 0;
        for (L += capacity, R += capacity; L < R; L /= 2, R /= 2)
        {
            if (L % 2 == 1)
                ret += tree[L++];
            if (R % 2 == 0)
                ret += tree[R--];
        }

        if (L == R)
            ret += tree[L];

        return ret;
    }

    void update(int idx, int val)
    {
        tree[capacity + idx] += val;
        for (int i = (capacity + idx) / 2; i > 0; i /= 2)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
};

void coordinate_compression(vector<int> &v, unordered_map<int, int> &idx)
{
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    size_t n = v.size();
    for (size_t i = 0; i < n; ++i)
        idx[v[i]] = i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        size_t n;
        cin >> n;

        vector<vector2> v(n);
        vector<int> y(n);
        for (size_t i = 0; i < n; ++i)
        {
            cin >> v[i].x >> v[i].y;
            y[i] = v[i].y;
        }

        unordered_map<int, int> y_idx;
        coordinate_compression(y, y_idx);

        ll ans = 0;
        size_t m = y_idx.size();
        segment_tree tree(m);

        sort(v.begin(), v.end());
        for (size_t i = 0; i < n; ++i)
        {
            int idx = y_idx[v[i].y];
            ans += tree.sum(idx, m - 1);
            tree.update(idx, 1);
        }

        cout << ans << '\n';
    }
}