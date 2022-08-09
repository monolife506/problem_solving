#include <iostream>
using namespace std;
typedef long long ll;

int num[100][100];
ll cache[100][100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cin >> num[i][j];
    }

    cache[0][0] = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (num[i][j] == 0)
                continue;

            if (i + num[i][j] < N)
                cache[i + num[i][j]][j] += cache[i][j];
            if (j + num[i][j] < N)
                cache[i][j + num[i][j]] += cache[i][j];
        }
    }

    cout << cache[N - 1][N - 1] << '\n';
}