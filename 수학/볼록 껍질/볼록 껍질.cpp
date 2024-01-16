#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct vector2
{
    int x;
    int y;
    explicit vector2(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
    bool operator<(const vector2 &rhs) const { return (x != rhs.x) ? x < rhs.x : y < rhs.y; }
};

// p를 기준으로 b가 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행하면 0 return
ll ccw(vector2 p, vector2 a, vector2 b)
{
    return 1LL * (a.x - p.x) * (b.y - p.y) - 1LL * (b.x - p.x) * (a.y - p.y);
}

// convex hull에 포함되는 점들을 return
vector<vector2> convexHull(vector<vector2> &points)
{
    vector<vector2> hull;
    int n = points.size();
    int m = 2; // hull size

    // pivot 정하기
    swap(points[0], *min_element(points.begin(), points.end()));

    // pivot 기준 반시계 방향 정렬
    vector2 &pivot = points[0];
    sort(points.begin() + 1,
         points.end(),
         [pivot](const vector2 &lhs, const vector2 &rhs) -> bool
         {
             ll dir = ccw(pivot, lhs, rhs);
             if (dir != 0)
                 return dir > 0;
             else
                 return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
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

    return hull;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector2> v(N);
    for (vector2 &p : v)
        cin >> p.x >> p.y;

    vector<vector2> convex_hull = convexHull(v);
    cout << convex_hull.size() << '\n';
}