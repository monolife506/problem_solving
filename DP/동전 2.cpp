#include <iostream>
using namespace std;

const int INF = 987654321;

int cost[100], cache[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> cost[i];
    for (int i = 0; i <= k; ++i)
        cache[i] = INF;

    cache[0] = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i + cost[j] <= k)
                cache[i + cost[j]] = min(cache[i + cost[j]], cache[i] + 1);
        }
    }

    cout << (cache[k] != INF ? cache[k] : -1) << '\n';
}