#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct vector2
{
    ll x, y, idx;
    explicit vector2(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    bool operator<(const vector2 &rhs) const { return (x != rhs.x) ? x < rhs.x : y < rhs.y; }
};

inline ll ccw(vector2 p, vector2 a, vector2 b)
{
    return (a.x - p.x) * (b.y - p.y) - (b.x - p.x) * (a.y - p.y);
}

void getPolygon(vector<vector2> &points)
{
    int k = points.size() - 1;

    // pivot 정하기
    swap(points[0], *min_element(points.begin(), points.end()));

    // pivot 기준 반시계 방향 정렬
    vector2 &pivot = points[0];
    sort(points.begin() + 1, points.end(),
         [pivot](const vector2 &lhs, const vector2 &rhs)
         {
             int dir = ccw(pivot, lhs, rhs);
             if (dir != 0)
                 return dir > 0;
             else
                 return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
         });

    while (ccw(pivot, points[k - 1], points[k]) == 0)
        k--;

    reverse(points.begin() + k, points.end());

    for (size_t i = 0; i < points.size(); i++)
        cout << points[i].idx << " ";

    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t c;
    cin >> c;
    for (size_t tc = 0; tc < c; tc++)
    {
        int n;
        cin >> n;

        vector<vector2> v(n);
        for (size_t i = 0; i < n; i++)
        {
            v[i].idx = i;
            cin >> v[i].x >> v[i].y;
        }

        getPolygon(v);
    }
}