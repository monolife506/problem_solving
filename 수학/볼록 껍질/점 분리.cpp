#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct vector2
{
    int x, y;
    explicit vector2(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator<(const vector2 &rhs) const { return (x != rhs.x) ? x < rhs.x : y < rhs.y; }
    bool operator==(const vector2 &rhs) const { return (x == rhs.x) && (y == rhs.y); }
};

int ccw(vector2 p, vector2 a, vector2 b)
{
    ll cross = 1LL * (a.x - p.x) * (b.y - p.y) - 1LL * (b.x - p.x) * (a.y - p.y);
    return (cross > 0) - (cross < 0);
}

bool lineIntersection(vector2 a1, vector2 a2, vector2 b1, vector2 b2)
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

bool insidePolygon(const vector<vector2> &polygon, vector2 p)
{
    int cross = ccw(polygon[0], polygon[1], p);
    for (int i = 1, n = polygon.size(); i < n; ++i)
    {
        int j = (i + 1) % n;
        if (cross != ccw(polygon[i], polygon[j], p))
            return false;
    }

    return true;
}

bool lineMeetPolygon(const vector<vector2> &polygon, vector2 a, vector2 b)
{
    if (insidePolygon(polygon, a) || insidePolygon(polygon, b))
        return true;

    for (int i = 0, n = polygon.size(); i < n; ++i)
    {
        int j = (i + 1) % n;
        if (lineIntersection(a, b, polygon[i], polygon[j]))
            return true;
    }

    return false;
}

bool meetPolygon(const vector<vector2> &p1, const vector<vector2> &p2)
{
    int n = p1.size(), m = p2.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int nxt_i = (i + 1) % n;
            int nxt_j = (j + 1) % m;

            if (insidePolygon(p1, p2[j]) || lineMeetPolygon(p1, p2[j], p2[nxt_j]))
                return true;
            if (insidePolygon(p2, p1[i]) || lineMeetPolygon(p2, p1[i], p1[nxt_i]))
                return true;
        }
    }

    return false;
}

void convexHull(vector<vector2> &points, vector<vector2> &hull)
{
    size_t n = points.size(), m = 2;

    for (size_t i = 1; i < n; i++)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector2> black_p(n), white_p(m);
        vector<vector2> black_hull, white_hull;
        for (vector2 &p : black_p)
            cin >> p.x >> p.y;
        for (vector2 &p : white_p)
            cin >> p.x >> p.y;

        if (n >= 3)
            convexHull(black_p, black_hull);
        if (m >= 3)
            convexHull(white_p, white_hull);

        bool flag;
        if (n == 1)
        {
            if (m == 1)
                flag = true;
            else if (m == 2)
                flag = (ccw(black_p[0], white_p[0], white_p[1]) != 0);
            else // m >= 3
                flag = !insidePolygon(white_hull, black_p[0]);
        }
        else if (n == 2)
        {
            if (m == 1)
                flag = (ccw(white_p[0], black_p[0], black_p[1]) != 0);
            else if (m == 2)
                flag = !lineIntersection(black_p[0], black_p[1], white_p[0], white_p[1]);
            else // m >= 3
                flag = !lineMeetPolygon(white_hull, black_p[0], black_p[1]);
        }
        else // n >= 3
        {
            if (m == 1)
                flag = !insidePolygon(black_hull, white_p[0]);
            else if (m == 2)
                flag = !lineMeetPolygon(black_hull, white_p[0], white_p[1]);
            else // m >= 3
                flag = !meetPolygon(black_hull, white_hull);
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}