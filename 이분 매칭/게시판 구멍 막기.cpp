#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, M, tape_num[2][51][51], tape_cnt[2];
char board[51][51];
vector<int> graph[2501];

bool visited[2501];
int matched[2501];

bool match(int cur)
{
    visited[cur] = true;
    for (int nxt : graph[cur])
    {
        if (matched[nxt] == -1 || (!visited[matched[nxt]] && match(matched[nxt])))
        {
            matched[nxt] = cur;
            return true;
        }
    }

    return false;
}

int max_match()
{
    memset(matched, -1, sizeof(matched));

    int match_cnt = 0;
    for (int i = 1; i <= tape_cnt[0]; ++i)
    {
        memset(visited, false, sizeof(visited));
        match_cnt += match(i);
    }

    return match_cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == '*')
            {
                if (i != 0 && board[i - 1][j] == '*')
                    tape_num[0][i][j] = tape_num[0][i - 1][j];
                else
                    tape_num[0][i][j] = ++tape_cnt[0];

                if (j != 0 && board[i][j - 1] == '*')
                    tape_num[1][i][j] = tape_num[1][i][j - 1];
                else
                    tape_num[1][i][j] = ++tape_cnt[1];

                graph[tape_num[0][i][j]].push_back(tape_num[1][i][j]);
            }
        }
    }

    cout << max_match() << '\n';
}

/*

1  1
2  2
3  3
4  4


*/