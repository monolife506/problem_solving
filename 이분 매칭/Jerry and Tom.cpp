#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Vector2
{
    int x, y;
    explicit Vector2(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const Vector2 &rhs) const { return (x != rhs.x) ? x < rhs.x : y < rhs.y; }
    bool operator==(const Vector2 &rhs) const { return (x == rhs.x) && (y == rhs.y); }
};

size_t N, K, H, M;
Vector2 corner[1000], hole[50], mouse[250];

vector<int> network[250];
int matched[250];
bool visited[250];

int ccw(Vector2 p, Vector2 a, Vector2 b)
{
    ll cross = 1LL * (a.x - p.x) * (b.y - p.y) - 1LL * (b.x - p.x) * (a.y - p.y);
    return (cross > 0) - (cross < 0);
}

bool line_intersection(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2)
{
    int dir1 = ccw(a1, a2, b1) * ccw(a1, a2, b2);
    int dir2 = ccw(b1, b2, a1) * ccw(b1, b2, a2);

    if (dir1 == 0 && dir2 == 0)
    {
        if (a2 < a1)
            swap(a1, a2);
        if (b2 < b1)
            swap(b1, b2);

        return ((b1 < a2) || (b1 == a2)) && ((a1 < b2) || (a1 == b2));
    }

    return (dir1 <= 0) && (dir2 <= 0);
}

bool match(int cur)
{
    if (visited[cur])
        return false;

    visited[cur] = true;
    for (int nxt : network[cur])
    {
        if (matched[nxt] == -1 || match(matched[nxt]))
        {
            matched[nxt] = cur;
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

    cin >> N >> K >> H >> M;
    for (size_t i = 0; i < N; ++i)
        cin >> corner[i].x >> corner[i].y;
    for (size_t i = 0; i < H; ++i)
        cin >> hole[i].x >> hole[i].y;
    for (size_t i = 0; i < M; ++i)
        cin >> mouse[i].x >> mouse[i].y;

    for (size_t i = 0; i < M; ++i)
    {
        for (size_t j = 0; j < H; ++j)
        {
            bool flag = true;
            for (size_t k = 0; k < N; ++k)
            {
                Vector2 &a = corner[k];
                Vector2 &b = corner[(k + 1) % N];

                if (a.x == b.x && a.x == hole[j].x)
                    continue;
                if (a.y == b.y && a.y == hole[j].y)
                    continue;

                if (line_intersection(mouse[i], hole[j], a, b))
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                for (size_t k = 0; k < K; ++k)
                    network[i].push_back(j * K + k);
            }
        }
    }

    int match_cnt = 0;
    memset(matched, -1, sizeof(matched));
    for (size_t i = 0; i < M; ++i)
    {
        memset(visited, false, sizeof(visited));
        match_cnt += match(i);
    }

    cout << (match_cnt == M ? "Possible" : "Impossible") << '\n';
}