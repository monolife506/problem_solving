#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 9;
ll cache[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    for (int i = 4; i <= 1000000; ++i)
    {
        if (i - 1 >= 1)
            cache[i] += cache[i - 1];
        if (i - 2 >= 1)
            cache[i] += cache[i - 2];
        if (i - 3 >= 1)
            cache[i] += cache[i - 3];

        cache[i] %= MOD;
    }

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        int n;
        cin >> n;

        cout << cache[n] << '\n';
    }
}