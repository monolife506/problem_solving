#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, c[2][200001], txt[400001], pat[200001], fail[200001];

void precomputation()
{
    sort(c[0], c[0] + n, greater<int>());
    sort(c[1], c[1] + n, greater<int>());
    for (size_t i = 0; i < n; i++)
    {
        txt[i] = (i != n - 1 ? c[0][i] - c[0][i + 1] : abs(c[0][i] - c[0][0]));
        if (txt[i] >= 180000)
            txt[i] = 360000 - txt[i];

        pat[i] = (i != n - 1 ? c[1][i] - c[1][i + 1] : abs(c[1][i] - c[1][0]));
        if (pat[i] >= 180000)
            pat[i] = 360000 - pat[i];

        txt[n + i] = txt[i];
    }
}

void computeFail()
{
    for (size_t i = 1, j = 0; i < n; i++)
    {
        while (j > 0 && pat[i] != pat[j])
            j = fail[j - 1];
        if (pat[i] == pat[j])
            fail[i] = ++j;
    }
}

bool kmp()
{
    for (size_t i = 0, j = 0; i < 2 * n; i++)
    {
        while (j > 0 && txt[i] != pat[j])
            j = fail[j - 1];
        if (txt[i] == pat[j])
        {
            if (j == n - 1)
                return true;
            else
                j++;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < n; j++)
            cin >> c[i][j];

    precomputation();
    computeFail();

    cout << (kmp() ? "possible" : "impossible") << '\n';
}