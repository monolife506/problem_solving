#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

int N, M;
int root[1000][1000];
char board[1000][1000];

int find(int x, int y)
{
    if (root[x][y] < 0)
        return x * M + y;
    return root[x][y] = find(root[x][y] / M, root[x][y] % M);
}

void merge(int ax, int ay, int bx, int by)
{
    int rootA = find(ax, ay);
    int rootB = find(bx, by);
    if (rootA != rootB)
    {
        if (rootA <= rootB)
            root[rootB / M][rootB % M] = rootA;
        else
            root[rootA / M][rootA % M] = rootB;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(root, -1, sizeof(root));

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (size_t j = 0; j < M; j++)
            board[i][j] = str[j];
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (board[i][j] == 'U')
                merge(i, j, i - 1, j);
            else if (board[i][j] == 'D')
                merge(i, j, i + 1, j);
            else if (board[i][j] == 'R')
                merge(i, j, i, j + 1);
            else
                merge(i, j, i, j - 1);
        }
    }

    int ans = 0;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (find(i, j) == i * M + j)
                ans++;
        }
    }
    cout << ans << '\n';
}

// 루프의 수 찾기
// 유니온 파인드: 루프에서

//