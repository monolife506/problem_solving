#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const double INF = 1e16;

struct vector2
{
    ll x, y;
    explicit vector2(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    bool operator<(const vector2 &rhs) const { return (y != rhs.y) ? y < rhs.y : x < rhs.x; }
    bool operator==(const vector2 &rhs) const { return x == rhs.x && y == rhs.y; }
};

typedef vector<vector2> Polygon;

inline ll ccw(vector2 p, vector2 a, vector2 b)
{
    return (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
}

// 점들에 대한 컨벡스 헐
Polygon getConvexHull(vector<vector2> &points)
{
    Polygon hull;
    int m = 2; // hull size

    // pivot 정하기
    swap(points[0], *min_element(points.begin(), points.end()));

    // pivot 기준 반시계 방향 정렬
    vector2 &pivot = points[0];
    sort(points.begin() + 1, points.end(),
         [pivot](const vector2 &lhs, const vector2 &rhs)
         {
             ll dir = ccw(pivot, lhs, rhs);
             if (dir != 0)
                 return dir > 0;
             else
                 return lhs.y != rhs.y ? lhs.y < rhs.y : lhs.x < rhs.x;
         });

    // 그라함 스캔으로 convex hull 구하기
    for (size_t i = 0; i < 2; i++)
        hull.push_back(points[i]);

    for (vector2 &p : points)
    {
        while (m >= 2 && ccw(hull[m - 2], hull[m - 1], p) <= 0)
        {
            hull.pop_back();
            m--;
        }

        hull.push_back(p);
        m++;
    }

    return hull;
}

// 직선 (a, b)와 p 사이의 거리
double getDist(vector2 p, vector2 a, vector2 b)
{
    double A = fabs((b.x - a.x) * (a.y - p.y) - (a.x - p.x) * (b.y - a.y));
    double B = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    return A / B;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);

    int n, case_num = 1;
    cin >> n;
    while (n != 0)
    {
        double ans = INF;
        Polygon points, convexHull;

        for (size_t i = 0; i < n; i++)
        {
            double x, y;
            cin >> x >> y;
            points.push_back(vector2(x, y));
        }

        convexHull = getConvexHull(points);

        // 각각의 변을 포함하는 직선에 대해 가장 멀리 떨어진 점과의 거리의 최솟값 찾기
        for (size_t i = 0; i < convexHull.size(); i++)
        {
            double dist = 0;
            vector2 &a = convexHull[i];
            vector2 &b = convexHull[(i + 1) % convexHull.size()];
            for (size_t j = 0; j < convexHull.size(); j++)
            {
                if (i == j || i + 1 == j)
                    continue;
                dist = max(dist, getDist(convexHull[j], a, b));
            }

            ans = min(ans, dist);
        }

        cout << "Case " << case_num++ << ": " << ceil(ans * 100) / 100 << '\n';
        cin >> n;
    }
}