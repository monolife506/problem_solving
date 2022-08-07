#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        cout << (str.length() >= 6 && str.length() <= 9 ? "yes" : "no") << '\n';
    }
}