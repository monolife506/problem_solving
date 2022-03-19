#include <iostream>
using namespace std;

int cache[31];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    cache[2] = 3;
    for (int i = 4; i <= N; i += 2)
    {
        cache[i] += cache[i - 2] * 3;
        for (int j = 4; i - j > 0; j += 2)
            cache[i] += cache[i - j] * 2;

        cache[i] += 2;
    }

    cout << cache[N] << '\n';
}