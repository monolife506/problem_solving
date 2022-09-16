#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll i = 4, ans = -1;
    while (ans == -1)
    {
        ll res[2];

        cout << "? " << 1 << " " << i << endl;
        cin >> res[0];
        if (res[0] == -1)
        {
            ans = i - 1;
            break;
        }

        cout << "? " << i << " " << 1 << endl;
        cin >> res[1];
        if (res[0] != res[1])
        {
            ans = res[0] + res[1];
            break;
        }

        ++i;
    }

    cout << "! " << ans << endl;
}