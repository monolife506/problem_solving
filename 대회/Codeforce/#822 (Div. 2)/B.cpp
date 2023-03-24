#include <iostream>
#include <vector>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
                cout << 1 << " ";
            else
                cout << 0 << " ";
        }

        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*

1
1 1

     1
    1 1
   1 0 1
  1 0 0 1
 1 0 0 0 1
1 0 0 0 0 1

*/