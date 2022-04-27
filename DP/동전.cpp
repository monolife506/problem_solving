#include <cstring>
#include <iostream>
using namespace std;

int value[20], cache[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        int N, M;
        memset(cache, 0, sizeof(cache));

        cin >> N;
        for (size_t i = 0; i < N; ++i)
            cin >> value[i];
        cin >> M;

        cache[0] = 1;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                if (j - value[i] >= 0)
                    cache[j] += cache[j - value[i]];
            }
        }

        cout << cache[M] << '\n';
    }
}