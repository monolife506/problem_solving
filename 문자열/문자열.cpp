#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        string str;
        cin >> str;
        cout << str.front() << str.back() << '\n';
    }
}