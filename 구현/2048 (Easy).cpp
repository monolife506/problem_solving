#include <iostream>
#include <vector>
using namespace std;

int N, ans;

void dfs(int cnt, int dir, vector<vector<int>> board)
{
    int max_num = 0;
    vector<vector<bool>> merged(N, vector<bool>(N, false));

    // 왼쪽 ~ 오른쪽
    if (dir == 0)
    {
        for (int i = 0; i < N; i++)
        {
            int empty = 20;
            for (int j = 0; j < N; j++)
            {
                int cur = j;
                if (board[i][j] == 0)
                {
                    empty = min(empty, j);
                    continue;
                }
                if (empty != 20)
                {
                    board[i][empty] = board[i][j];
                    board[i][j] = 0;
                    cur = empty++;
                }
                if (cur > 0 && board[i][cur] == board[i][cur - 1] && !merged[i][cur - 1])
                {
                    merged[i][cur - 1] = true;
                    board[i][cur - 1] *= 2;
                    board[i][cur] = 0;
                    empty = cur;
                    max_num = max(max_num, board[i][cur - 1]);
                }
                max_num = max(max_num, board[i][j]);
            }
        }
    }
    else if (dir == 1)
    {
        // 위쪽 ~ 아래쪽
        for (int i = 0; i < N; i++)
        {
            int empty = 20;
            for (int j = 0; j < N; j++)
            {
                int cur = j;
                if (board[j][i] == 0)
                {
                    empty = min(empty, j);
                    continue;
                }
                if (empty != 20)
                {
                    board[empty][i] = board[j][i];
                    board[j][i] = 0;
                    cur = empty++;
                }
                if (cur > 0 && board[cur][i] == board[cur - 1][i] && !merged[cur - 1][i])
                {
                    merged[cur - 1][i] = true;
                    board[cur - 1][i] *= 2;
                    board[cur][i] = 0;
                    empty = cur;
                    max_num = max(max_num, board[cur - 1][i]);
                }
                max_num = max(max_num, board[j][i]);
            }
        }
    }
    else if (dir == 2)
    {
        // 오른쪽 ~ 왼쪽
        for (int i = N - 1; i >= 0; i--)
        {
            int empty = -1;
            for (int j = N - 1; j >= 0; j--)
            {
                int cur = j;
                if (board[i][j] == 0)
                {
                    empty = max(empty, j);
                    continue;
                }
                if (empty != -1)
                {
                    board[i][empty] = board[i][j];
                    board[i][j] = 0;
                    cur = empty--;
                }
                if (cur < N - 1 && board[i][cur] == board[i][cur + 1] && !merged[i][cur + 1])
                {
                    merged[i][cur + 1] = true;
                    board[i][cur + 1] *= 2;
                    board[i][cur] = 0;
                    empty = cur;
                    max_num = max(max_num, board[i][cur + 1]);
                }
                max_num = max(max_num, board[i][j]);
            }
        }
    }
    else
    {
        // 아래쪽 ~ 위쪽
        for (int i = N - 1; i >= 0; i--)
        {
            int empty = -1;
            for (int j = N - 1; j >= 0; j--)
            {
                int cur = j;
                if (board[j][i] == 0)
                {
                    empty = max(empty, j);
                    continue;
                }
                if (empty != -1)
                {
                    board[empty][i] = board[j][i];
                    board[j][i] = 0;
                    cur = empty--;
                }
                if (cur < N - 1 && board[cur][i] == board[cur + 1][i] && !merged[cur + 1][i])
                {
                    merged[cur + 1][i] = true;
                    board[cur + 1][i] *= 2;
                    board[cur][i] = 0;
                    empty = cur;
                    max_num = max(max_num, board[cur + 1][i]);
                }
                max_num = max(max_num, board[j][i]);
            }
        }
    }

    if (cnt == 5)
    {
        ans = max(ans, max_num);
        return;
    }

    for (size_t i = 0; i < 4; i++)
        dfs(cnt + 1, i, board);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            cin >> board[i][j];
    }

    for (size_t i = 0; i < 4; i++)
        dfs(1, i, board);

    cout << ans << '\n';
}

// 위로 옮기면
// 위쪽 블럭부터 아래쪽 블럭까지 위로 옮기기
// 만나면 그 윗 블럭과 합치고 합쳤다고 표시