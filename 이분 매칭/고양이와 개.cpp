#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_V = 500;

int matched[MAX_V];
bool visited[MAX_V];

bool match(int cur, vector<vector<int>> &bigraph)
{
    if (visited[cur])
        return false;

    visited[cur] = true;
    for (int nxt : bigraph[cur])
    {
        if (matched[nxt] == -1 || match(matched[nxt], bigraph))
        {
            matched[nxt] = cur;
            return true;
        }
    }

    return false;
}

int bipartite_matching(vector<vector<int>> &bigraph)
{
    int match_cnt = 0;

    memset(matched, -1, sizeof(matched));
    for (int i = 0; i < bigraph.size(); ++i)
    {
        memset(visited, false, sizeof(visited));
        match_cnt += match(i, bigraph);
    }

    return match_cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        int c, d, v;
        cin >> c >> d >> v;

        vector<pair<int, int>> l, r;
        for (int i = 0; i < v; ++i)
        {
            string pass, fail;
            cin >> pass >> fail;

            int pass_num = stoi(pass.substr(1));
            int fail_num = stoi(fail.substr(1));

            if (pass[0] == 'C')
                l.push_back({pass_num, fail_num});
            else // pass[0] == 'D'
                r.push_back({pass_num, fail_num});
        }

        vector<vector<int>> bigraph(l.size());
        for (int i = 0; i < l.size(); ++i)
        {
            for (int j = 0; j < r.size(); ++j)
            {
                if (l[i].first == r[j].second || l[i].second == r[j].first)
                    bigraph[i].push_back(j);
            }
        }

        cout << v - bipartite_matching(bigraph) << '\n';
    }
}