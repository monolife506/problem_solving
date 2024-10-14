#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<vector<int>> make_tree(string &s)
{
    vector<vector<int>> tree(2);

    int cur = 1;
    int cnt = 1;

    stack<int> st;
    for (char c : s)
    {
        if (c == '0')
        {
            st.push(cur);
            tree[cur].push_back(++cnt);
            tree.push_back(vector<int>());
            cur = cnt;
        }
        else
        {
            cur = st.top();
            st.pop();
        }
    }

    return tree;
}

string gen_tree_string(int cur, vector<vector<int>> &tree)
{
    string ret = "";
    vector<string> v;

    for (int nxt : tree[cur])
        v.push_back(gen_tree_string(nxt, tree));

    sort(v.begin(), v.end());
    for (const string &s : v)
        ret += s;

    return "(" + ret + ")";
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> t1 = make_tree(s1);
    vector<vector<int>> t2 = make_tree(s2);

    cout << gen_tree_string(1, t1) << '\n';
    cout << gen_tree_string(1, t2) << '\n';
    cout << (gen_tree_string(1, t1) == gen_tree_string(1, t2)) << '\n';
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