#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<ll> nums;
    map<ll, ll> mex;

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        char type;
        cin >> type;

        if (type == '+')
        {
            ll x;
            cin >> x;
            nums.insert(x);
        }
        else // type == '?'
        {
            ll k;
            cin >> k;

            if (nums.find(k) == nums.end())
            {
                cout << k << '\n';
            }
            else if (mex.find(k) != mex.end() && nums.find(mex[k]) == nums.end())
            {
                cout << mex[k] << '\n';
            }
            else
            {
                if (mex.find(k) == mex.end())
                    mex[k] = k * 2;
                while (nums.find(mex[k]) != nums.end())
                    mex[k] += k;

                cout << mex[k] << '\n';
            }
        }
    }
}