#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct vector2
{
    ll x, y;
    explicit vector2(ll x = 0, ll y = 0) : x(x), y(y) {}

    vector2 operator-(const vector2 &rhs) { return vector2(x - rhs.x, y - rhs.y); }
};

int ccw(vector2 p, vector2 a, vector2 b)
{
    ll cross = (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
    return (cross > 0) - (cross < 0);
}

int ccw2(vector2 a, vector2 b, vector2 c, vector2 d)
{
    d.x -= (c.x - b.x);
    d.y -= (c.y - b.y);
    return ccw(a, b, d);
}

inline double dist(vector2 a, vector2 b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void convexHull(vector<vector2> &points, vector<vector2> &hull)
{
    size_t n = points.size(), m = 2;

    for (size_t i = 1; i < n; i++)
    {
        bool flag1 = points[i].y < points[0].y;
        bool flag2 = (points[i].y == points[0].y) && (points[i].x < points[0].x);
        if (flag1 || flag2)
            swap(points[0], points[i]);
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

pair<vector2, vector2> rotatingCalipers(vector<vector2> &points)
{
    vector<vector2> hull;
    convexHull(points, hull);

    size_t n = hull.size();
    size_t pl = 0, pr = 0;

    vector2 &pivot = hull[0];
    sort(hull.begin() + 1, hull.end(),
         [pivot](const vector2 &lhs, const vector2 &rhs) -> bool
         {
             int dir = ccw(pivot, lhs, rhs);
             if (dir != 0)
                 return dir > 0;
             else
                 return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
         });

    for (size_t i = 0; i < n; i++)
    {
        if (hull[i].x < hull[pl].x)
            pl = i;
        if (hull[i].x > hull[pr].x)
            pr = i;
    }

    double max_dist = dist(hull[pl], hull[pr]);
    size_t idx1 = pl, idx2 = pr;

    for (size_t i = 0; i <= n; ++i)
    {
        if (ccw2(hull[pl], hull[(pl + 1) % n], hull[pr], hull[(pr + 1) % n]) > 0)
            pr = (pr + 1) % n;
        else
            pl = (pl + 1) % n;

        double d = dist(hull[pl], hull[pr]);
        if (max_dist < d)
        {
            max_dist = d;
            idx1 = pl;
            idx2 = pr;
        }
    }

    return {hull[idx1], hull[idx2]};
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
        int n;
        cin >> n;

        vector<vector2> points(n);
        for (vector2 &p : points)
            cin >> p.x >> p.y;

        pair<vector2, vector2> ans = rotatingCalipers(points);
        cout << ans.first.x << " " << ans.first.y << " ";
        cout << ans.second.x << " " << ans.second.y << '\n';
    }
}