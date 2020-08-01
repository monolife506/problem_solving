#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Map
{
    int land;          // 지형 번호
    int unitTeam = -1; // 현재 위치에 있는 유닛의 팀 (-1 == 없음)
};

struct Unit
{
    int m; // 이동력
    int t; // 팀
    int a; // current H
    int b; // current W
};

struct pqItem
{
    int w; // 현재 거리
    int a; // current H
    int b; // current W

    pqItem(int w, int a, int b)
    {
        this->w = w;
        this->a = a;
        this->b = b;
    }
};

struct cmp
{
    bool operator()(pqItem A, pqItem B)
    {
        return A.w > B.w;
    }
};

int N, H, W, M, K;
Map map[500][500];
Unit units[62501];
int landscape[10];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool checkBattle(int unitNum, int A, int B)
{
    for (size_t i = 0; i < 4; i++)
    {
        int nextA = A + dy[i];
        int nextB = B + dx[i];
        if (nextA >= H || nextA < 0)
            continue;
        if (nextB >= W || nextB < 0)
            continue;
        if (map[nextA][nextB].unitTeam != -1 && map[nextA][nextB].unitTeam != units[unitNum].t)
            return true;
    }
    return false;
}

void movement(int unitNum, int A, int B) // 다익스트라
{
    if (landscape[map[A][B].land] == -1 || map[A][B].unitTeam != -1)
        return;

    int dist[500][500];
    bool visited[500][500];
    priority_queue<pqItem, vector<pqItem>, cmp> pq;
    memset(dist, -1, sizeof(dist));
    memset(visited, 0, sizeof(visited));

    Unit &curUnit = units[unitNum];
    dist[curUnit.a][curUnit.b] = 0;
    pq.push(pqItem(0, curUnit.a, curUnit.b));
    while (!pq.empty())
    {
        int curA, curB;
        do
        {
            curA = pq.top().a;
            curB = pq.top().b;
            pq.pop();
        } while (!pq.empty() && visited[curA][curB]);

        if (visited[curA][curB] || dist[curA][curB] > curUnit.m)
            break;

        visited[curA][curB] = true;
        for (size_t i = 0; i < 4; i++)
        {
            int nextA = curA + dy[i];
            int nextB = curB + dx[i];
            if (nextA >= H || nextA < 0)
                continue;
            if (nextB >= W || nextB < 0)
                continue;
            if (landscape[map[nextA][nextB].land] == -1 || (map[nextA][nextB].unitTeam != -1 && map[nextA][nextB].unitTeam != curUnit.t))
                continue;
            if (checkBattle(unitNum, nextA, nextB) && (nextA != A || nextB != B))
                continue;

            int weight = landscape[map[nextA][nextB].land];
            if (dist[curA][curB] + weight < dist[nextA][nextB] || dist[nextA][nextB] == -1)
            {
                dist[nextA][nextB] = dist[curA][curB] + weight;
                if (A == nextA && B == nextB && dist[A][B] <= curUnit.m)
                {
                    map[curUnit.a][curUnit.b].unitTeam = -1;
                    curUnit.a = A;
                    curUnit.b = B;
                    map[curUnit.a][curUnit.b].unitTeam = curUnit.t;
                    break;
                }
                if (!visited[nextA][nextB])
                    pq.push(pqItem(dist[nextA][nextB], nextA, nextB));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H >> W;
    for (size_t i = 0; i < H; i++)
    {
        for (size_t j = 0; j < W; j++)
        {
            cin >> map[i][j].land;
        }
    }
    for (size_t i = 1; i <= N; i++)
        cin >> landscape[i];

    cin >> M;
    for (size_t i = 1; i <= M; i++)
    {
        cin >> units[i].m >> units[i].t >> units[i].a >> units[i].b;
        map[units[i].a][units[i].b].unitTeam = units[i].t;
    }

    cin >> K;
    for (size_t i = 0; i < K; i++)
    {
        int U, A, B;
        cin >> U >> A >> B;
        movement(U, A, B);
    }

    for (size_t i = 1; i <= M; i++)
        cout << units[i].a << " " << units[i].b << '\n';
}