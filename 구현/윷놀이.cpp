#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i < 3; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < 4; ++j)
        {
            bool flag;
            cin >> flag;
            cnt += flag;
        }

        if (cnt == 4)
        {
            cout << 'E' << '\n';
        }
        else if (cnt == 3)
        {
            cout << 'A' << '\n';
        }
        else if (cnt == 2)
        {
            cout << 'B' << '\n';
        }
        else if (cnt == 1)
        {
            cout << 'C' << '\n';
        }
        else
        {
            cout << 'D' << '\n';
        }
    }
}