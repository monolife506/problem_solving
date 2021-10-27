#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct vector2
{
    int x;
    int y;
    explicit vector2(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

typedef vector<vector2> polygon;

// p를 기준으로 b가 a의 반시계 방향이면 양수, 시계방향이면 음수, 평행하면 0
// return
int ccw(vector2 p, vector2 a, vector2 b)
{
    return (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
}

// convex hull에 포함되는 점들을 return
polygon
convexHull(const vector<vector2> &points)
{
    polygon hull;
    int n = points.size();
    int m = 3; // hull size

    vector2 pivot;

    // pivot 기준 반시계 방향 정렬
    sort(points.begin(),
         points.end(),
         [pivot](const vector2 &a, const vector2 &b) -> bool
         {
             int dir = ccw(pivot, a, b);
             if (dir == 0)
                 return (a.x != b.x) ? (a.x < b.x) : (a.y < b.y);
             else
                 return (dir == 1);
         });
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

    polygon convex_hull = convexHull(v);
    cout << convex_hull.size() << '\n';
}