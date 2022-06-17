#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int N, W[1 << 18];
P p[1 << 18];

void inorder(int cur, int h)
{
    static int x = 1;

    if (cur * 2 <= N)
        inorder(cur * 2, h + 1);

    p[x].first = W[cur];
    p[x].second = h;
    x++;

    if (cur * 2 + 1 <= N)
        inorder(cur * 2 + 1, h + 1);
}

ll dp(int l, int r)
{
    ll cache = 0, ret = INT64_MIN;
    for (int i = 1; i <= N; i++)
    {
        if (p[i].second < l || p[i].second > r)
            continue;

        if (cache <= 0)
            cache = p[i].first;
        else
            cache += p[i].first;

        ret = max(ret, cache);
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> W[i];

    inorder(1, 0);

    ll ans = INT64_MIN;
    for (int l = 0; l < 18; ++l)
    {
        for (int r = l; r < 18; ++r)
            ans = max(ans, dp(l, r));
    }

    cout << ans << '\n';
}