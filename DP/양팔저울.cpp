#include <iostream>
using namespace std;

int W[30];
bool cache[31][40001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> W[i];

    cache[0][0] = true;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= 40000; ++j)
        {
            if (cache[i][j])
            {
                cache[i + 1][j] = true;
                cache[i + 1][j + W[i]] = true;
                cache[i + 1][abs(j - W[i])] = true;
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int w;
        cin >> w;
        cout << (cache[N][w] ? "Y" : "N") << " ";
    }

    cout << '\n';
}