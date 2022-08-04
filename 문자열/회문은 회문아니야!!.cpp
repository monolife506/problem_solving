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

    int l = 0;
    int r = str.length() - 1;

    bool is_palindrome = true;
    while (l < r)
    {
        if (str[l] != str[r])
            is_palindrome = false;

        ++l;
        --r;
    }

    if (is_palindrome)
    {
        bool is_single_char = true;
        for (int i = 1; i < str.length(); ++i)
        {
            if (str[i] != str[i - 1])
                is_single_char = false;
        }

        if (is_single_char)
            cout << -1 << '\n';
        else
            cout << str.length() - 1 << '\n';
    }
    else
    {
        cout << str.length() << '\n';
    }
}