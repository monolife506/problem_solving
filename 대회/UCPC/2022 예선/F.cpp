#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;

char tilemap[51][51], id[1001];
int cnt[2][26], idx[26];
vector<P> p[26];

void move_to(P a, P b, string &str)
{
    string s;
    if (a.first < b.first)
    {
        for (int i = 0; i < b.first - a.first; ++i)
            s.push_back('D');
    }
    else if (a.first > b.first)
    {
        for (int i = 0; i < a.first - b.first; ++i)
            s.push_back('U');
    }

    if (a.second < b.second)
    {
        for (int i = 0; i < b.second - a.second; ++i)
            s.push_back('R');
    }
    else if (a.second > b.second)
    {
        for (int i = 0; i < a.second - b.second; ++i)
            s.push_back('L');
    }

    str += s;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S;
    cin >> N >> M >> S;
    for (int i = 0; i < N; ++i)
    {
        cin >> tilemap[i];
        for (int j = 0; j < M; ++j)
        {
            p[tilemap[i][j] - 'a'].push_back({i, j});
            cnt[0][tilemap[i][j] - 'a']++;
        }
    }

    cin >> id;
    for (int i = 0; i < S; ++i)
        cnt[1][id[i] - 'a']++;

    int C = INT32_MAX;
    for (int i = 0; i < 26; ++i)
    {
        if (cnt[1][i] != 0)
            C = min(C, cnt[0][i] / cnt[1][i]);
    }

    string str = "";
    P cur = {0, 0};
    for (int c = 0; c < C; ++c)
    {
        for (int i = 0; i < S; ++i)
        {
            move_to(cur, p[id[i] - 'a'][idx[id[i] - 'a']], str);
            str += "P";
            cur = p[id[i] - 'a'][idx[id[i] - 'a']];
            idx[id[i] - 'a']++;
        }
    }

    move_to(cur, {N - 1, M - 1}, str);
    cout << C << " " << str.size() << '\n';
    cout << str << '\n';
}