#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        ll n, x, y;
        cin >> n >> x >> y;

        string a, b;
        cin >> a >> b;

        vector<ll> diff;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != b[i])
                diff.push_back(i);
        }

        int diff_cnt = diff.size();
        if (diff_cnt % 2 == 1)
        {
            cout << -1 << '\n';
        }
        else if (diff_cnt == 0)
        {
            cout << 0 << '\n';
        }
        else if (x >= y)
        {
            if (diff_cnt == 2)
            {
                if (n == 2)
                {
                    cout << x << '\n';
                }
                else if (diff[0] + 1 == diff[1])
                {
                    cout << min(x, y * 2) << '\n';
                }
                else
                {
                    cout << y << '\n';
                }
            }
            else
            {
                cout << 1LL * (diff_cnt / 2) * y << '\n';
            }
        }
        else
        {
            vector<ll> cache(diff_cnt + 1, 0);
            for (int i = 1; i < diff_cnt; ++i)
            {
                cache[i + 1] = cache[i];
                cache[i + 1] = max(cache[i + 1], cache[i - 1] + y - ((diff[i] - diff[i - 1]) * x));
            }

            cout << (y * diff_cnt / 2) - cache[diff_cnt] << '\n';
        }
    }
}

/*

l r
min((r - l) * x, y)

abcd

ad bc
bd ac
cd ab

abcdef

af bcde
bf acde
cf abde
df abce
ef abcd

*/