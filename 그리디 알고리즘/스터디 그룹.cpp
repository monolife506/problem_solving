#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

P s[100000];
int set[30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, D;
    cin >> N >> K >> D;
    for (int i = 0; i < N; ++i)
    {
        int M;
        cin >> M >> s[i].first;
        for (int j = 0; j < M; ++j)
        {
            int A;
            cin >> A;
            s[i].second |= (1 << (A - 1));
        }
    }

    sort(s, s + N);

    int l = 0, r = 0, ans = 0;
    for (int k = 0; k < K; ++k)
    {
        if (s[0].second & (1 << k))
            ++set[k];
    }

    while (l < N && r < N)
    {
        if (s[r].first - s[l].first <= D)
        {
            int union_cnt = 0;
            int intersection_cnt = 0;
            for (int k = 0; k < K; ++k)
            {
                if (set[k] > 0)
                    ++union_cnt;
                if (set[k] == (r - l + 1))
                    ++intersection_cnt;
            }

            ans = max(ans, (union_cnt - intersection_cnt) * (r - l + 1));

            if (r + 1 < N)
            {
                ++r;
                for (int k = 0; k < K; ++k)
                {
                    if (s[r].second & (1 << k))
                        ++set[k];
                }
            }
            else
            {
                for (int k = 0; k < K; ++k)
                {
                    if (s[l].second & (1 << k))
                        --set[k];
                }
                ++l;
            }
        }
        else
        {
            for (int k = 0; k < K; ++k)
            {
                if (s[l].second & (1 << k))
                    --set[k];
            }
            ++l;
        }
    }

    cout << ans << '\n';
}