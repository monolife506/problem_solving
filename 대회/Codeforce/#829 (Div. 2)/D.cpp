#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> cnt(x + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        cnt[a]++;
    }

    bool flag = true;
    for (int i = 1; i < x; ++i)
    {
        if (cnt[i] >= i + 1)
        {
            cnt[i + 1] += cnt[i] / (i + 1);
            cnt[i] %= i + 1;
        }

        if (cnt[i] != 0)
            flag = false;
    }

    if (cnt[x] == 0)
        flag = false;

    cout << (flag ? "Yes" : "No") << '\n';
}

/*

1! 1 = 2! - 1!
2! 2 = 3! - 2!
3! 3 = 4! - 3!
4! 4 = 5! - 4!

5! - 1!

*/