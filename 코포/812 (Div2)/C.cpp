#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> square_num;
    for (int i = 0; i * i <= 200000; ++i)
        square_num.push_back(i * i);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        int n;
        cin >> n;

        vector<int> p(n, -1);

        int num = n - 1;
        auto lb = lower_bound(square_num.begin(), square_num.end(), num);
        if (lb == square_num.end())
        {
            cout << -1 << '\n';
            continue;
        }

        int idx = *lb - num;

        bool flag = true;
        while (true)
        {
            if (p[idx] != -1)
            {
                flag = false;
                break;
            }

            while (idx < n && p[idx] == -1)
                p[idx++] = num--;

            if (num < 0)
                break;

            lb = lower_bound(square_num.begin(), square_num.end(), num);
            idx = *lb - num;
        }

        if (!flag)
        {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 0; i < n; ++i)
            cout << p[i] << " ";

        cout << '\n';
    }
}

/*

n <- p[k^2 - n]

0
1 0
1 0 2
0 3 2 1
4 3 2 1 0
0 3 2 1 5 4
1 0 2 6 5 4 3
1 0 7 6 5 4 3 2
0 8 7 6 5 4 3 2 1
9 8 7 6 5 4 3 2 1 0
0 3 2 1 5 4 10 9 8 7 6

*/