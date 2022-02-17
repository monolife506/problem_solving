#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> network[2001];
int match_a[2001], match_b[1001];
bool visited[2001];

bool match(int cur)
{
    if (visited[cur])
        return false;

    visited[cur] = true;
    for (int nxt : network[cur])
    {
        if (match_b[nxt] == -1 || match(match_b[nxt]))
        {
            match_a[cur] = nxt;
            match_b[nxt] = cur;
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
        size_t cnt;
        cin >> cnt;
        for (size_t j = 0; j < cnt; ++j)
        {
            int n;
            cin >> n;
            network[2 * i].push_back(n);
            network[2 * i - 1].push_back(n);
        }
    }

    memset(match_a, -1, sizeof(match_a));
    memset(match_b, -1, sizeof(match_b));

    int match_cnt[2] = {0, 0};
    for (size_t i = 1; i <= N; ++i)
    {
        if (match_a[i * 2 - 1] == -1)
        {
            memset(visited, false, sizeof(visited));
            if (match(i * 2 - 1))
                match_cnt[0]++;
        }
    }
    for (size_t i = 1; i <= N; ++i)
    {
        if (match_a[i * 2] == -1)
        {
            memset(visited, false, sizeof(visited));
            if (match(i * 2))
            {
                match_cnt[1]++;
                if (match_cnt[1] == K)
                    break;
            }
        }
    }

    cout << match_cnt[0] + match_cnt[1] << '\n';
}