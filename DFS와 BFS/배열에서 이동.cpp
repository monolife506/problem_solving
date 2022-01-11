#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;
typedef pair<int, int> P;

int n, arr[MAX + 1][MAX + 1];

bool bfs(int min_num, int max_num)
{
    static const int dx[] = {1, -1, 0, 0};
    static const int dy[] = {0, 0, 1, -1};

    queue<P> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));

    if (arr[1][1] >= min_num && arr[1][1] <= max_num)
    {
        q.push(P(1, 1));
        visited[1][1] = true;
    }

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int nxt_y = y + dy[i];
            int nxt_x = x + dx[i];
            if (nxt_y <= 0 || nxt_y > n || nxt_x <= 0 || nxt_x > n)
                continue;
            if (visited[nxt_y][nxt_x] || arr[nxt_y][nxt_x] < min_num || arr[nxt_y][nxt_x] > max_num)
                continue;

            visited[nxt_y][nxt_x] = true;
            q.push(P(nxt_y, nxt_x));
        }
    }

    return visited[n][n];
}

bool check(int diff)
{
    for (int i = 0; i + diff <= 200; i++)
    {
        if (bfs(i, i + diff))
            return true;
    }

    return false;
}

int binary_search()
{
    int left = 0;
    int right = 200;
    int ret = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
        {
            ret = mid;
            if (mid == 0)
                break;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (size_t i = 1; i <= n; i++)
        for (size_t j = 1; j <= n; j++)
            cin >> arr[i][j];

    cout << binary_search() << '\n';
}