#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getFail(const string &pattern)
{
    int m = pattern.length();
    vector<int> fail(m, 0);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
            j = fail[j - 1];
        if (pattern[i] == pattern[j])
            fail[i] = ++j;
    }

    return fail;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;
    while (str != ".")
    {
        vector<int> fail = getFail(str);
        if (str.size() % (str.size() - fail.back()) == 0)
            cout << str.size() / (str.size() - fail.back()) << '\n';
        else
            cout << 1 << '\n';

        cin >> str;
    }
}