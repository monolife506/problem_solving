#include <cstring>
#include <iostream>
using namespace std;

int c[20], cache[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        memset(cache, 0, sizeof(cache));
        cache[0] = 1;

        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> c[i];

        int M;
        cin >> M;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                if (j - c[i] >= 0)
                    cache[j] += cache[j - c[i]];
            }
        }

        cout << cache[M] << '\n';
    }
}