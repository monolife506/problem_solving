#include <iostream>
using namespace std;

const int INF = 987654321;
int A[1000], cache[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill_n(&cache[0], 1000, INF);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    cache[0] = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 1; j <= A[i]; ++j)
        {
            if (i + j < N)
                cache[i + j] = min(cache[i + j], cache[i] + 1);
        }
    }

    cout << (cache[N - 1] != INF ? cache[N - 1] : -1) << '\n';
}