#include <iostream>
using namespace std;

struct vector2
{
    int x, y;
    explicit vector2(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    int squaredDist(const vector2 &rhs)
    {
        return (x - rhs.x) * (x - rhs.x) + (y - rhs.y) * (y - rhs.y);
    }
};

const int MAX_N = 1000;
const int INF = 987654321;

vector2 points[MAX_N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;

    int ans_idx = -1;
    int ans_dist = INF;
    for (size_t i = 0; i < n; i++)
    {
        int max_dist = 0;
        for (size_t j = 0; j < n; j++)
            max_dist = max(max_dist, points[i].squaredDist(points[j]));

        if (max_dist < ans_dist)
        {
            ans_dist = max_dist;
            ans_idx = i;
        }
    }

    cout << points[ans_idx].x << " " << points[ans_idx].y << '\n';
}