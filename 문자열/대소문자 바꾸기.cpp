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
    for (char c : str)
    {
        if (c >= 'A' && c <= 'Z')
            cout << (char)(c + 32);
        else
            cout << (char)(c - 32);
    }

    cout << '\n';
}