#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    while (cin >> N)
    {
        vector<pii> p(N);
        for (int i = 0; i < N; ++i)
            cin >> p[i].first >> p[i].second;

        sort(p.begin(), p.end());

        int ans = 1, l = p[0].first, r = p[0].second;
        for (int i = 1; i < N; ++i)
        {
            if (l > p[i].second || r < p[i].first)
            {
                ++ans;
                l = p[i].first;
                r = p[i].second;
            }
            else
            {
                l = max(l, p[i].first);
                r = min(r, p[i].second);
            }
        }

        cout << ans << '\n';
    }
}

/*

4 4
1 4
2 4
3 4

6
1 2
1 3
1 4
1 5
2 5
1 10

*/