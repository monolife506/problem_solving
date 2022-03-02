#include <iostream>
#include <string>
#include <vector>
using namespace std;

void get_fail(const string &str, vector<int> &fail)
{
    int n = str.size();
    fail.resize(n, 0);
    for (int i = 1, j = 0; i < n; ++i)
    {
        while (j > 0 && str[i] != str[j])
            j = fail[j - 1];
        if (str[i] == str[j])
            fail[i] = ++j;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int L;
    string str;
    cin >> L >> str;

    vector<int> fail;
    get_fail(str, fail);
    cout << L - fail[L - 1] << '\n';
}