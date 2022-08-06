#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        bool is_decrease = false;
        bool flag = true;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] > a[i - 1])
            {
                if (is_decrease)
                    flag = false;
            }
            else if (a[i] < a[i - 1])
            {
                if (!is_decrease)
                    is_decrease = true;
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}

/*

1 2 3
0 1 2
0 0 1
0 0 0

1 3 2

0 2 1


3

*/