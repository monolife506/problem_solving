#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Vector2
{
    int x, y;
    explicit Vector2(int x = 0, int y = 0) : x(x), y(y) {}
    Vector2 operator-(const Vector2 &rhs)
    {
        return Vector2(x - rhs.x, y - rhs.y);
    }

    int ccw(const Vector2 &a, const Vector2 &b)
    {
        ll cross = 1LL * (a.x - x) * (b.y - y) - 1LL * (b.x - x) * (a.y - y);
        return (cross > 0) - (cross < 0);
    }
    ll dist(const Vector2 &rhs)
    {
        return 1LL * (x - rhs.x) * (x - rhs.x) + 1LL * (y - rhs.y) * (y - rhs.y);
    }
};

void convex_hull(vector<Vector2> &points, vector<Vector2> &hull)
{
    for (size_t i = 1; i < points.size(); ++i)
    {
        if (points[0].y > points[i].y)
            swap(points[0], points[i]);
        else if (points[0].y == points[i].y && points[0].x > points[i].x)
            swap(points[0], points[i]);
    }

    sort(points.begin() + 1, points.end(),
         [&](const Vector2 &lhs, const Vector2 &rhs) -> bool
         {
             int dir = points[0].ccw(lhs, rhs);
             if (dir != 0)
                 return dir > 0;
             else
                 return (lhs.y != rhs.y) ? lhs.y < rhs.y : lhs.x < rhs.x;
         });

    for (size_t i = 0; i < points.size(); ++i)
    {
        while (hull.size() >= 2 && hull[hull.size() - 2].ccw(hull[hull.size() - 1], points[i]) <= 0)
            hull.pop_back();
        hull.push_back(points[i]);
    }
}

pair<Vector2, Vector2> rotating_calipers(vector<Vector2> &points)
{
    vector<Vector2> hull;
    convex_hull(points, hull);

    size_t pl = 0, pr = 0;
    for (size_t i = 0; i < hull.size(); ++i)
    {
        if (hull[i].x < hull[pl].x)
            pl = i;
        if (hull[i].x > hull[pr].x)
            pr = i;
    }

    ll max_dist = hull[pl].dist(hull[pr]);
    size_t ret1 = pl, ret2 = pr;
    for (size_t i = 0; i <= hull.size(); ++i)
    {
        size_t nxt_pl = (pl + 1) % hull.size();
        size_t nxt_pr = (pr + 1) % hull.size();
        if (hull[pl].ccw(hull[nxt_pl], hull[nxt_pr] - (hull[pr] - hull[nxt_pl])) <= 0)
            pl = nxt_pl;
        else
            pr = nxt_pr;

        ll dist = hull[pl].dist(hull[pr]);
        if (dist > max_dist)
        {
            max_dist = dist;
            ret1 = pl;
            ret2 = pr;
        }
    }

    return {hull[ret1], hull[ret2]};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        size_t N;
        cin >> N;

        vector<Vector2> points(N);
        for (size_t i = 0; i < N; ++i)
            cin >> points[i].x >> points[i].y;

        pair<Vector2, Vector2> ans = rotating_calipers(points);
        cout << ans.first.x << " " << ans.first.y << " "
             << ans.second.x << " " << ans.second.y << '\n';
    }
}