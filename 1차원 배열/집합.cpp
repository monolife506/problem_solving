// 11723번: 집합
// 비트마스크의 기초

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int S = 0;
    int M;
    cin >> M;
    for (size_t i = 0; i < M; i++)
    {
        int x;
        string input;
        cin >> input;

        if (input == "add")
        {
            cin >> x;
            S |= (1 << x);
        }
        else if (input == "remove")
        {
            cin >> x;
            S &= ~(1 << x);
        }
        else if (input == "check")
        {
            cin >> x;
            cout << ((S & (1 << x)) ? "1" : "0") << '\n';
        }
        else if (input == "toggle")
        {
            cin >> x;
            S ^= (1 << x);
        }
        else if (input == "all")
            S = (1 << 21) - 1;
        else if (input == "empty")
            S = 0;
    }
}