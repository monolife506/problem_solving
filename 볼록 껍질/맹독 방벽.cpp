#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct vector2
{
    int x, y;
    explicit vector2(int x = 0, int y = 0) : x(x), y(y) {}

    vector2 operator-(const vector2 &rhs) const
    {
        return vector2(x - rhs.x, y - rhs.y);
    }

    inline double norm() { return sqrt(x * x + y * y); }
};

inline int ccw(const vector2 &p, const vector2 &a, const vector2 &b)
{
    return (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
}

void convexHull(vector<vector2> &points, vector<vector2> &hull)
{
    size_t n = points.size(), m = 2;

    for (size_t i = 1; i < n; i++) // pivot 찾기
    {
        bool flag1 = points[i].y < points[0].y;
        bool flag2 = (points[i].y == points[0].y) && (points[i].x < points[0].x);
        if (flag1 || flag2)
        {
            vector2 tmp(points[0].x, points[0].y);
            points[0] = points[i];
            points[i] = tmp;
        }
    }

    // pivot 기준 반시계 방향 정렬
    vector2 &pivot = points[0];
    sort(points.begin() + 1,
         points.end(),
         [pivot](const vector2 &lhs, const vector2 &rhs) -> bool
         {
             int dir = ccw(pivot, lhs, rhs);
             if (dir != 0)
                 return dir > 0;
             else
                 return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
         });

    // 그라함 스캔으로 convex hull 구하기
    for (size_t i = 0; i < 2; i++)
        hull.push_back(points[i]);

    for (size_t i = 2; i < n; i++)
    {
        while (m >= 2 && ccw(hull[m - 2], hull[m - 1], points[i]) <= 0)
        {
            hull.pop_back();
            m--;
        }

        hull.push_back(points[i]);
        m++;
    }
}

inline double dist(const vector2 &lhs, const vector2 &rhs)
{
    return sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y));
}

double arc(int L, const vector2 &a, const vector2 &b, const vector2 &c)
{
    double angle1 = atan2((double)(b - a).x, (double)(b - a).y);
    double angle2 = atan2((double)(b - c).x, (double)(b - c).y);

    if (angle1 < 0)
        angle1 += 2.0 * M_PI;
    if (angle2 < 0)
        angle2 += 2.0 * M_PI;

    double angle = abs(angle1 - angle2);
    if (angle > M_PI)
        angle = 2.0 * M_PI - angle;

    return L * (M_PI - angle);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, L;
    cin >> N >> L;

    double ans = 0.0;
    vector<vector2> points(N);
    vector<vector2> hull;

    for (vector2 &p : points)
        cin >> p.x >> p.y;

    convexHull(points, hull);
    for (size_t i = 0, hull_size = hull.size(); i < hull_size; ++i)
    {
        vector2 &cur = hull[i];
        vector2 &nxt = hull[(i + 1) % hull_size];
        vector2 &pre = hull[(i + hull_size - 1) % hull_size];

        ans += dist(cur, nxt);
        ans += arc(L, pre, cur, nxt);
    }

    cout << (int)round(ans) << '\n';
}
