#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N, M;
int root[1000][1000];
int board[1000][1000];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int find(int x, int y)
{
    if (root[x][y] < 0)
        return x * M + y;
    return root[x][y] = find(root[x][y] / M, root[x][y] % M);
}

int size(int x, int y)
{
    int curRoot = find(x, y);
    x = curRoot / M;
    y = curRoot % M;
    return abs(root[x][y]);
}

void merge(int ax, int ay, int bx, int by)
{
    int rootA = find(ax, ay);
    int rootB = find(bx, by);
    if (rootA != rootB)
    {
        root[rootA / M][rootA % M] += root[rootB / M][rootB % M];
        root[rootB / M][rootB % M] = rootA;
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
            board[i][j] = str[j] - '0';
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (board[i][j] > 0)
                continue;

            for (size_t k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x < 0 || x >= N || y < 0 || y >= M)
                    continue;
                if (board[x][y] > 0)
                    continue;

                merge(i, j, x, y);
            }
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
                continue;

            vector<int> roots;
            for (size_t k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x < 0 || x >= N || y < 0 || y >= M)
                    continue;
                if (board[x][y] > 0)
                    continue;

                int curRoot = find(x, y);
                int curSize = size(x, y);
                bool flag = false;

                for (int num : roots)
                {
                    if (curRoot == num)
                        flag = true;
                }

                if (flag)
                    continue;

                roots.push_back(curRoot);
                board[i][j] += curSize;
            }
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
            cout << board[i][j] % 10;
        cout << '\n';
    }
}