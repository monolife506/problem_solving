#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll cache[4][100001];
char c[] = {'D', 'K', 'S', 'H'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    string S;
    cin >> S;

    for (int i = 0; i < N; ++i)
    {
        cache[0][i + 1] = cache[0][i];
        if (S[i] == c[0])
            ++cache[0][i + 1];
    }
    for (int i = 1; i < 4; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cache[i][j + 1] = cache[i][j];
            if (S[j] == c[i])
                cache[i][j + 1] += cache[i - 1][j];
        }
    }

    cout << cache[3][N] << '\n';
}