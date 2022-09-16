#include <iostream>
#include <vector>
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
        int n;
        cin >> n;

        vector<int> c(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> c[i];

        bool flag = true;
        int child_cnt = c[1];
        for (int i = 1; i < n; ++i)
        {
            if (c[i] < c[i + 1] || child_cnt < c[i + 1] * 2)
            {
                flag = false;
                break;
            }

            child_cnt -= c[i + 1];
        }

        if (c[n] > 2 || child_cnt != 2)
            flag = false;
        if (n >= 3 && c[n] == 1 && (c[n - 1] < 2 || c[n - 1] > 3))
            flag = false;
        if (n >= 3 && c[n] == 2 && (c[n - 1] < 2 || c[n - 1] > 4))
            flag = false;

        cout << (flag ? "YES" : "NO") << '\n';
    }
}

/*

can't do backwards

    8 9 10
    | | |
1-2-3-4-5-6-7
12 5 2 2 1

12 > 10 -> 7
7 > 4 -> 5
5 > 4 -> 3
3 > 1 -> 2

*/