#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> network[2001];
int match_l[2001], match_r[1001];
bool visited[2001], connected[1001];

bool match(int cur)
{
    if (visited[cur])
        return false;

    visited[cur] = true;
    for (int nxt : network[cur])
    {
        if (match_r[nxt] == -1 || match(match_r[nxt]))
        {
            match_l[cur] = nxt;
            match_r[nxt] = cur;
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t N, M, K;
    cin >> N >> M >> K;
    for (size_t i = 1; i <= N; ++i)
    {
        int cnt;
        cin >> cnt;
        for (size_t j = 0; j < cnt; ++j)
        {
            int n;
            cin >> n;
            network[i].push_back(n);
            connected[n] = true;
        }
    }

    for (size_t i = 1; i <= K; ++i)
    {
        for (size_t j = 1; j <= M; ++j)
        {
            if (connected[j])
                network[N + i].push_back(j);
        }
    }

    memset(match_l, -1, sizeof(match_l));
    memset(match_r, -1, sizeof(match_r));

    int match_cnt = 0;
    for (size_t i = 1; i <= N + K; ++i)
    {
        if (match_l[i] == -1)
        {
            memset(visited, false, sizeof(visited));
            if (match(i))
                match_cnt++;
        }
    }

    cout << match_cnt << '\n';
}