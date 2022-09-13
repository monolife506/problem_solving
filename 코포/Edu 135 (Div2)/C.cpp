#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (size_t tc = 0; tc < t; ++tc)
    {
        int n;
        cin >> n;

        unordered_multiset<int> a, b;
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            a.insert(num);
        }
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;

            auto it = a.find(num);
            if (it != a.end())
                a.erase(it);
            else
                b.insert(num);
        }

        int ans = 0;
        vector<vector<int>> cnt(2, vector<int>(10, 0));
        for (int num : a)
        {
            if (num >= 10)
            {
                ++ans;
                ++cnt[0][to_string(num).size()];
            }
            else
            {
                ++cnt[0][num];
            }
        }
        for (int num : b)
        {
            if (num >= 10)
            {
                ++ans;
                ++cnt[1][to_string(num).size()];
            }
            else
            {
                ++cnt[1][num];
            }
        }

        for (int i = 2; i <= 9; ++i)
            ans += abs(cnt[0][i] - cnt[1][i]);

        cout << ans << '\n';
    }
}

/*

2 9 3
1 3 9

log -> 1 ~ 9

1 2
2 1


1 1 7 7 8 9 9
1 1 1 1 2 3 4

1 3

7
8
9

*/
