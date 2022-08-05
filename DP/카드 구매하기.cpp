#include <iostream>
using namespace std;

int N, P[10001], cache[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> P[i];
        for (int j = i; j <= N; ++j)
            cache[j] = max(cache[j], cache[j - i] + P[i]);
    }

    cout << cache[N] << '\n';
}