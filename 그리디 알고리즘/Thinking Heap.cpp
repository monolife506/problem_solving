#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int N, k, p, tree[1 << 18];

int get_parent_cnt(int root)
{
    int ret = 0;
    for (int i = root / 2; i > 0; i /= 2)
    {
        tree[i] = -1;
        ++ret;
    }

    return ret;
}

int get_child_cnt(int root, int cur)
{
    if (cur > N)
        return 0;
    if (cur != root)
        tree[cur] = 1;

    int ret = get_child_cnt(root, cur * 2) + get_child_cnt(root, cur * 2 + 1);
    return (cur == root) ? ret : ret + 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> k >> p;

    int parent_cnt = get_parent_cnt(p);
    int child_cnt = get_child_cnt(p, p);

    if (parent_cnt > k - 1 || child_cnt > N - k)
    {
        cout << -1 << '\n';
    }
    else
    {
        int parent_num = 1;
        int child_num = k + 1;
        int other_num[2] = {parent_cnt + 1, child_cnt + k + 1};
        for (int i = 1; i <= N; ++i)
        {
            if (tree[i] == 1)
                cout << child_num++ << '\n';
            else if (tree[i] == -1)
                cout << parent_num++ << '\n';
            else if (i == p)
                cout << k << '\n';
            else
            {
                if (other_num[0] < k)
                    cout << other_num[0]++ << '\n';
                else if (other_num[1] <= N)
                    cout << other_num[1]++ << '\n';
            }
        }
    }
}