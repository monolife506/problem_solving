#include <algorithm>
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

    int ans = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        vector<int> fail = getFail(str.substr(i));
        ans = max(ans, *max_element(fail.begin(), fail.end()));
    }

    cout << ans << '\n';
}