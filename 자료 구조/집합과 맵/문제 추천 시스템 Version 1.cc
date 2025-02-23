#include <bits/stdc++.h>
#define endl '\n';
using namespace std;

typedef pair<int, int> pii;

void sol()
{
    int n;
    cin >> n;

    set<pii> s;
    vector<int> diff(100001, -1);
    for (int i = 0; i < n; ++i)
    {
        int p, l;
        cin >> p >> l;
        s.insert({diff[p] = l, p});
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string q;
        cin >> q;

        if (q == "recommend")
        {
            int x;
            cin >> x;

            cout << ((x == 1) ? s.rbegin()->second : s.begin()->second) << endl;
        }
        else if (q == "add")
        {
            int p, l;
            cin >> p >> l;
            s.insert({diff[p] = l, p});
        }
        else // q == "solved"
        {
            int p;
            cin >> p;

            s.erase({diff[p], p});
            diff[p] = -1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sol();
}