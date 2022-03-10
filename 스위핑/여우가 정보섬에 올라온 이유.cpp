#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

struct vector2
{
    int x, y, idx;
    explicit vector2(int x = 0, int y = 0, int idx = 0) : x(x), y(y), idx(idx) {}
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

bool cmp1(const vector2 &lhs, const vector2 &rhs)
{
    return (lhs.x != rhs.x) ? lhs.x < rhs.x : lhs.y > rhs.y;
}

bool cmp2(const vector2 &lhs, const vector2 &rhs)
{
    return (lhs.x != rhs.x) ? lhs.x > rhs.x : lhs.y > rhs.y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N;
    cin >> N;

    vector<vector2> star(N);
    vector<ll> left_cnt(N), right_cnt(N);
    for (size_t i = 0; i < N; ++i)
    {
        cin >> star[i].x >> star[i].y;
        star[i].idx = i;
        star[i].y += 200000;
    }

    segment_tree tree(400001);
    sort(star.begin(), star.end(), cmp1);
    vector<int> y_on_this_x;
    for (size_t i = 0; i < N; ++i)
    {
        left_cnt[star[i].idx] = tree.sum(star[i].y + 1, 400000);
        y_on_this_x.push_back(star[i].y);
        if (i == N - 1 || star[i].x != star[i + 1].x)
        {
            while (!y_on_this_x.empty())
            {
                tree.update(y_on_this_x.back(), 1);
                y_on_this_x.pop_back();
            }
        }
    }

    memset(tree.tree, 0, sizeof(int) * tree.capacity * 2);
    sort(star.begin(), star.end(), cmp2);
    for (size_t i = 0; i < N; ++i)
    {
        right_cnt[star[i].idx] = tree.sum(star[i].y + 1, 400000);
        y_on_this_x.push_back(star[i].y);
        if (i == N - 1 || star[i].x != star[i + 1].x)
        {
            while (!y_on_this_x.empty())
            {
                tree.update(y_on_this_x.back(), 1);
                y_on_this_x.pop_back();
            }
        }
    }

    ll ans = 0;
    for (size_t i = 0; i < N; ++i)
        ans = (ans + ((left_cnt[i] * right_cnt[i]) % MOD)) % MOD;

    cout << ans << '\n';
}