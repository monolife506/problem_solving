#include <iostream>
using namespace std;

int root[500000];

int find(int cur)
{
    if (root[cur] < 0)
        return cur;
    return root[cur] = find(root[cur]);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false; // no merge

    root[b] = a;
    return true; // merged
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;

    for (size_t i = 0; i < n; i++) {
        root[i] = -1;
    }

    for (size_t i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (ans == 0 && !merge(a, b))
            ans = i + 1;
    }

    cout << ans << '\n';
}