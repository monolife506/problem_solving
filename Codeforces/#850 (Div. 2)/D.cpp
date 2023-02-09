#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, char, int, char> tp;

void solve()
{
    int m;
    cin >> m;

    map<string, vector<int>> idx;
    for (int i = 1; i <= m; ++i)
    {
        string s;
        cin >> s;

        sort(s.begin(), s.end());
        idx[s].push_back(i);
    }

    vector<tp> ans;

    while (!idx["www"].empty())
    {
        if (!idx["iii"].empty())
        {
            int a = idx["www"].back();
            int b = idx["iii"].back();
            idx["www"].pop_back();
            idx["iii"].pop_back();
            idx["iww"].push_back(a);
            idx["iiw"].push_back(b);
            ans.push_back({a, 'w', b, 'i'});
        }
        else if (!idx["nnn"].empty())
        {
            int a = idx["www"].back();
            int b = idx["nnn"].back();
            idx["www"].pop_back();
            idx["nnn"].pop_back();
            idx["nww"].push_back(a);
            idx["nnw"].push_back(b);
            ans.push_back({a, 'w', b, 'n'});
        }
        else if (!idx["iin"].empty())
        {
            int a = idx["www"].back();
            int b = idx["iin"].back();
            idx["www"].pop_back();
            idx["iin"].pop_back();
            idx["iww"].push_back(a);
            idx["inw"].push_back(b);
            ans.push_back({a, 'w', b, 'i'});
        }
        else if (!idx["inn"].empty())
        {
            int a = idx["www"].back();
            int b = idx["inn"].back();
            idx["www"].pop_back();
            idx["inn"].pop_back();
            idx["nww"].push_back(a);
            idx["inw"].push_back(b);
            ans.push_back({a, 'w', b, 'n'});
        }
        else
        {
            break;
        }
    }
    while (!idx["iii"].empty())
    {
        if (!idx["nnn"].empty())
        {
            int a = idx["iii"].back();
            int b = idx["nnn"].back();
            idx["iii"].pop_back();
            idx["nnn"].pop_back();
            idx["iin"].push_back(a);
            idx["inn"].push_back(b);
            ans.push_back({a, 'i', b, 'n'});
        }
        else if (!idx["nnw"].empty())
        {
            int a = idx["iii"].back();
            int b = idx["nnw"].back();
            idx["iii"].pop_back();
            idx["nnw"].pop_back();
            idx["iin"].push_back(a);
            idx["inw"].push_back(b);
            ans.push_back({a, 'i', b, 'n'});
        }
        else if (!idx["nww"].empty())
        {
            int a = idx["iii"].back();
            int b = idx["nww"].back();
            idx["iii"].pop_back();
            idx["nww"].pop_back();
            idx["iiw"].push_back(a);
            idx["inw"].push_back(b);
            ans.push_back({a, 'i', b, 'w'});
        }
        else
        {
            break;
        }
    }
    while (!idx["nnn"].empty())
    {
        if (!idx["iww"].empty())
        {
            int a = idx["nnn"].back();
            int b = idx["iww"].back();
            idx["nnn"].pop_back();
            idx["iww"].pop_back();
            idx["nnw"].push_back(a);
            idx["inw"].push_back(b);
            ans.push_back({a, 'n', b, 'w'});
        }
        else if (!idx["iiw"].empty())
        {
            int a = idx["nnn"].back();
            int b = idx["iiw"].back();
            idx["nnn"].pop_back();
            idx["iiw"].pop_back();
            idx["inn"].push_back(a);
            idx["inw"].push_back(b);
            ans.push_back({a, 'n', b, 'i'});
        }
        else
        {
            break;
        }
    }

    while (!idx["iiw"].empty() && !idx["nnw"].empty())
    {
        int a = idx["iiw"].back();
        int b = idx["nnw"].back();
        idx["iiw"].pop_back();
        idx["nnw"].pop_back();
        idx["inw"].push_back(a);
        idx["inw"].push_back(b);
        ans.push_back({a, 'i', b, 'n'});
    }
    while (!idx["iww"].empty() && !idx["inn"].empty())
    {
        int a = idx["iww"].back();
        int b = idx["inn"].back();
        idx["iww"].pop_back();
        idx["inn"].pop_back();
        idx["inw"].push_back(a);
        idx["inw"].push_back(b);
        ans.push_back({a, 'w', b, 'n'});
    }
    while (!idx["nww"].empty() && !idx["iin"].empty())
    {
        int a = idx["nww"].back();
        int b = idx["iin"].back();
        idx["nww"].pop_back();
        idx["iin"].pop_back();
        idx["inw"].push_back(a);
        idx["inw"].push_back(b);
        ans.push_back({a, 'w', b, 'i'});
    }

    while (!idx["iiw"].empty() && !idx["inn"].empty() && !idx["nww"].empty())
    {
        int a = idx["iiw"].back();
        int b = idx["inn"].back();
        int c = idx["nww"].back();
        idx["iiw"].pop_back();
        idx["inn"].pop_back();
        idx["nww"].pop_back();
        idx["inw"].push_back(a);
        idx["inw"].push_back(b);
        idx["inw"].push_back(c);
        ans.push_back({a, 'i', b, 'n'});
        ans.push_back({b, 'i', c, 'w'});
    }
    while (!idx["iww"].empty() && !idx["nnw"].empty() && !idx["iin"].empty())
    {
        int a = idx["iww"].back();
        int b = idx["nnw"].back();
        int c = idx["iin"].back();
        idx["iww"].pop_back();
        idx["nnw"].pop_back();
        idx["iin"].pop_back();
        idx["inw"].push_back(a);
        idx["inw"].push_back(b);
        idx["inw"].push_back(c);
        ans.push_back({a, 'w', b, 'n'});
        ans.push_back({b, 'w', c, 'i'});
    }

    cout << ans.size() << '\n';
    for (auto t : ans)
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " " << get<3>(t) << '\n';
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

1
www - iii
www - iin
www - inn
www - nnn
iii - wwn
iii - wnn
iii - nnn
nnn - wwi
nnn - wii

1
wii - wnn
wwi - inn
wwn - iin

2
wii - inn - wwn
wwi - wnn - iin

*/