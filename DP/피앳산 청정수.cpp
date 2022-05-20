#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

P p[1000];
int cache[1001][6001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> p[i].first >> p[i].second;

    sort(p, p + N, [](P &lhs, P &rhs) -> bool
         { return (lhs.first + lhs.second) < (rhs.first + rhs.second); });

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= 6000; ++j)
        {
            cache[i + 1][j] = max(cache[i + 1][j], cache[i][j]);
            if (j + p[i].first <= 6000 && p[i].second > j)
                cache[i + 1][j + p[i].first] = max(cache[i + 1][j + p[i].first], cache[i][j] + 1);
        }
    }

    int max_c = 0, min_p = 6000;
    for (int j = 0; j <= 6000; ++j)
    {
        if (max_c < cache[N][j] || (max_c == cache[N][j] && min_p > j))
        {
            max_c = cache[N][j];
            min_p = j;
        }
    }

    cout << max_c << " " << min_p << '\n';
}