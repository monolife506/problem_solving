#include <iostream>
using namespace std;

int cnt[20];

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

        int max_cnt = 0, idx = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> cnt[i];
            if (max_cnt < cnt[i])
            {
                max_cnt = max(max_cnt, cnt[i]);
                idx = i;
            }
        }

        cout << idx << '\n';
    }
}

/*

total odd

odd - odd cnt
even - whatever

10
4 4 2

100 * 20 = 2000

*/