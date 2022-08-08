#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    cin >> str;

    bool flag = true;
    for (int i = 0; i < str.length() / 2; ++i)
    {
        if (str[i] != str[str.length() - (i + 1)])
            flag = false;
    }

    cout << flag << '\n';
}