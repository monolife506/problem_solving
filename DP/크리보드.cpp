#include <iostream>
using namespace std;
typedef long long ll;

ll cache[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    cache[1] = 1;
    for (int i = 1; i <= N; ++i)
    {
        cache[i + 1] = max(cache[i + 1], cache[i] + 1);
        for (int j = 1; i + j + 2 <= N; ++j)
            cache[i + j + 2] = max(cache[i + j + 2], cache[i] * (j + 1));
    }

    cout << cache[N] << '\n';
}