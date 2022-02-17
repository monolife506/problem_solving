#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> network[501];
int match_a[501], match_b[501];
bool visited[501];

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

    size_t n, k;
    cin >> n >> k;
    for (size_t i = 0; i < k; i++)
    {
        int row, column;
        cin >> row >> column;
        network[row].push_back(column);
    }

    memset(match_a, -1, sizeof(match_a));
    memset(match_b, -1, sizeof(match_b));

    int match_cnt = 0;
    for (size_t i = 1; i <= n; i++)
    {
        if (match_a[i] == -1)
        {
            memset(visited, false, sizeof(visited));
            if (match(i))
                match_cnt++;
        }
    }

    cout << match_cnt << '\n';
}