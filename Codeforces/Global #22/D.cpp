#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n + 1);

    int k = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        if (b[i] > i)
            ++k;
    }

    cout << k << '\n';

    vector<vector<int>> nxt(n + 2);
    vector<vector<int>> pre(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        nxt[b[i]].push_back(i);
    }

    int last = -1, cnt = 0;
    if (!nxt[n + 1].empty())
    {
        for (int num : nxt[n + 1])
        {
            if (!nxt[num].empty())
                last = num;
            else
                cout << num << " ";
        }

        if (last != -1)
            cout << last << " ";

        cnt += nxt[n + 1].size();
    }
    else // !nxt[0].empty()
    {
        for (int num : nxt[0])
        {
            if (!nxt[num].empty())
                last = num;
            else
                cout << num << " ";
        }

        if (last != -1)
            cout << last << " ";

        cnt += nxt[0].size();
    }

    if (last != -1)
    {
        while (cnt != n)
        {
            int nxt_last = -1;
            for (int num : nxt[last])
            {
                if (!nxt[num].empty())
                    nxt_last = num;
                else
                    cout << num << " ";
            }

            cnt += nxt[last].size();
            if (nxt_last != -1)
                cout << nxt_last << " ";

            last = nxt_last;
        }
    }

    cout << '\n';
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


b[i] = 값이 i인 a[i]의
-> a 이전의 값 중 k보다 큰 값이고 가장 가까운 값, 없으면 n + 1 (x <= k)
-> a 이전의 값 중 k 이하인 값이고 가장 가까운 값, 없으면 0 (x > k)

6
7 7 7 3 3 3
1 2 3 4 5 6




*/