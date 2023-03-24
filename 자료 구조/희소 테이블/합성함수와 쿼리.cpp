#include <iostream>
using namespace std;

const int MAX_M = 200000;
const int MAX_LOG_M = 18;

int table[MAX_LOG_M + 1][MAX_M + 1]; // sparse table

void precomputation(int m)
{
    for (size_t i = 1; i <= MAX_LOG_M; i++)
    {
        for (size_t j = 1; j <= m; j++)
        {
            table[i][j] = table[i - 1][table[i - 1][j]];
        }
    }
}

int query(int n, int x)
{
    for (int i = MAX_LOG_M; i >= 0; i--)
    {
        if (n >= (1 << i))
        {
            x = table[i][x];
            n -= (1 << i);
        }
    }

    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, Q, n, x;
    cin >> m;
    for (size_t i = 1; i <= m; i++)
        cin >> table[0][i];

    precomputation(m);
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> n >> x;
        cout << query(n, x) << '\n';
    }
}