#include <cstring>
#include <iostream>
using namespace std;

int root[300001];

int find(int n)
{
    if (root[n] == -1)
        return n;
    else
        return root[n] = find(root[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        root[b] = a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    int N;
    cin >> N;
    for (int i = 0; i < N - 2; ++i)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    int ans1 = -1, ans2 = -1;
    for (int i = 1; i <= N; ++i)
    {
        if (ans1 == -1)
        {
            ans1 = i;
        }
        else if (ans2 == -1 && find(ans1) != find(i))
        {
            ans2 = i;
            break;
        }
    }

    cout << ans1 << " " << ans2 << '\n';
}