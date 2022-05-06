#include <iostream>
using namespace std;

int num[1000001], cache[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> num[i];

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        cache[num[i]] = cache[num[i] - 1] + 1;
        ans = max(ans, cache[num[i]]);
    }

    cout << N - ans << '\n';
}