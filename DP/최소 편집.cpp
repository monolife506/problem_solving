#include <iostream>
#include <string>
using namespace std;

int cache[1001][1001];

int solve(const string &from, const string &to)
{
    for (size_t i = 0; i <= from.length(); i++)
        for (size_t j = 0; j <= to.length(); j++)
            cache[i][j] = 987654321;

    cache[0][0] = 0;
    for (size_t i = 0; i <= from.length(); i++)
    {
        for (size_t j = 0; j <= to.length(); j++)
        {
            if (i < from.length() && j < to.length())
            {
                if (from[i] == to[j])
                    cache[i + 1][j + 1] = min(cache[i + 1][j + 1], cache[i][j]);
                else // from[i] != to[j]
                    cache[i + 1][j + 1] = min(cache[i + 1][j + 1], cache[i][j] + 1);
            }

            if (i < from.length())
                cache[i + 1][j] = min(cache[i + 1][j], cache[i][j] + 1);
            if (j < to.length())
                cache[i][j + 1] = min(cache[i][j + 1], cache[i][j] + 1);
        }
    }

    return cache[from.length()][to.length()];
}

int main()
{
    string from, to;
    cin >> from >> to;
    cout << solve(from, to) << '\n';
}