#include <iostream>
#include <array>
#include <queue>
using namespace std;

struct P // 박스의 위치를 표시하는 구조체
{
    int x;
    int y;
    int z;
};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int M, N, H;    // 박스의 가로, 세로, 높이
int remain = 0; // 익지 않은 토마토의 개수
queue<P> Q;     // BFS에서 사용될 큐

array<array<array<int, 101>, 101>, 101> box; // box[z][y][x] == (x, y, z)위치의 토마토의 정보

int bfs()
{
    int max_day = 1; // 마지막으로 토마토가 익었을 때의 숫자
    while (!Q.empty() && remain != 0)
    {
        P cur = Q.front();
        Q.pop();

        for (size_t i = 0; i < 6; i++)
        {
            int x = cur.x + dx[i];
            int y = cur.y + dy[i];
            int z = cur.z + dz[i];

            if (x < 0 || x >= M)
                continue;
            if (y < 0 || y >= N)
                continue;
            if (z < 0 || z >= H)
                continue;

            if (box[z][y][x] == 0)
            {
                box[z][y][x] = box[cur.z][cur.y][cur.x] + 1;
                Q.push({x, y, z});

                remain--;
                max_day = max(max_day, box[z][y][x]);
            }
        }
    }

    if (remain != 0) // 모든 토마토가 익지 않은 상태이므로, -1 return
        return -1;
    else                    // 모든 토마토가 익었다면
        return max_day - 1; // 토마토가 익는데 걸리는 일수 return
}

int main()
{

    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                    Q.push({k, j, i}); // 처음에 채워진 토마토들을 전부 큐에 넣어주어야 한다.
                else if (box[i][j][k] == 0)
                    remain += 1; // 추가로 익어야 할 토마토의 개수를 더해준다.
            }
        }
    }

    cout << bfs();
}