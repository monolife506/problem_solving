#include <cstring>
#include <iostream>
#include <string>
using namespace std;

bool cache[201][201];

bool check(const string &a, const string &b, const string &c)
{
    memset(cache, false, sizeof(cache));
    cache[0][0] = true;

    for (size_t i = 0; i <= a.length(); i++)
    {
        for (size_t j = 0; j <= b.length(); j++)
        {
            if (i < a.length() && a[i] == c[i + j] && cache[i][j])
                cache[i + 1][j] = true;
            if (j < b.length() && b[j] == c[i + j] && cache[i][j])
                cache[i][j + 1] = true;
        }
    }

    return cache[a.length()][b.length()];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        cout << "Data set " << i << ": "
             << (check(a, b, c) ? "yes" : "no") << '\n';
    }
}