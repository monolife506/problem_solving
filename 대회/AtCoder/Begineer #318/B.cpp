#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int cnt[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        for (int y = C; y < D; ++y)
        {
            for (int x = A; x < B; ++x)
                cnt[y][x]++;
        }
    }

    int ans = 0;
    for (int y = 0; y < 100; ++y)
    {
        for (int x = 0; x < 100; ++x)
        {
            if (cnt[y][x] > 0)
                ans++;
        }
    }

    cout << ans << '\n';
}