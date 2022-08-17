#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ans = -1, r, c;
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            int num;
            cin >> num;
            if (ans < num)
            {
                ans = num;
                r = i;
                c = j;
            }
        }
    }

    cout << ans << '\n';
    cout << r << " " << c << '\n';
}