#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    unordered_set<string> substr;
    for (size_t i = 0; i < S.length(); ++i)
    {
        for (size_t j = 1; i + j <= S.length(); ++j)
            substr.insert(S.substr(i, j));
    }

    cout << substr.size() << '\n';
}