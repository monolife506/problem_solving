#include <iostream>
#include <string>
using namespace std;

int cache[101][101][101];

int lcs(const string &a, const string &b, const string &c)
{
    for (size_t i = 0; i <= a.length(); i++)
    {
        for (size_t j = 0; j <= b.length(); j++)
        {
            for (size_t k = 0; k <= c.length(); k++)
            {
                if (i < a.length() && j < b.length() && k < c.length() && a[i] == b[j] && a[i] == c[k])
                    cache[i + 1][j + 1][k + 1] = cache[i][j][k] + 1;

                if (i < a.length())
                    cache[i + 1][j][k] = max(cache[i + 1][j][k], cache[i][j][k]);
                if (j < b.length())
                    cache[i][j + 1][k] = max(cache[i][j + 1][k], cache[i][j][k]);
                if (k < c.length())
                    cache[i][j][k + 1] = max(cache[i][j][k + 1], cache[i][j][k]);
            }
        }
    }

    return cache[a.length()][b.length()][c.length()];
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    cout << lcs(a, b, c) << '\n';
}