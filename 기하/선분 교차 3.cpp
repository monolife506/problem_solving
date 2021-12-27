#include <iomanip>
#include <iostream>
using namespace std;
typedef long long ll;

template <typename T>
struct vector2
{
    T x, y;
    explicit vector2(T _x = 0, T _y = 0) : x(_x), y(_y) {}

    bool operator==(const vector2 &rhs) const { return x == rhs.x && y == rhs.y; }
    bool operator<(const vector2 &rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; }
};

// 선분 (a, b)와 (c, d)의 교차 여부 확인
// 1: 교점 존재, -1: 교선 존재, 0: 교차하지 않음
int segmentIntersection(vector2<ll> a, vector2<ll> b, vector2<ll> c, vector2<ll> d, vector2<double> &p)
{
    if (b < a)
        swap(a, b);
    if (d < c)
        swap(c, d);

    ll divisor = (d.y - c.y) * (b.x - a.x) - (d.x - c.x) * (b.y - a.y);
    ll t_dividend = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    ll s_dividend = (b.x - a.x) * (a.y - c.y) - (b.y - a.y) * (a.x - c.x);

    if (divisor == 0) // 두 선분이 평행한 경우
    {
        if (t_dividend == 0 && s_dividend == 0) // 두 직선은 일치함
        {
            if (b < c || d < a)
                return 0; // 두 선분은 만나지 않음

            if (b == c)
            {
                p.x = b.x;
                p.y = b.y;
                return 1; // 두 선분은 점 b에서 만남
            }
            if (a == d)
            {
                p.x = a.x;
                p.y = a.y;
                return 1; // 두 선분은 점 a에서 만남
            }

            return -1; // 두 선분은 서로 겹침
        }

        return 0; // 두 직선이 일치하지 않아 교점이 존재하지 않음
    }

    double t = (double)t_dividend / divisor;
    double s = (double)s_dividend / divisor;

    if (t < 0.0 || t > 1.0 || s < 0.0 || s > 1.0)
        return 0; // 교점이 선분 밖 직선 위에 존재함

    p.x = a.x + t * (b.x - a.x);
    p.y = a.y + t * (b.y - a.y);
    return 1; // 선분 사이에 교점이 존재함
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector2<ll> a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    vector2<double> p;
    int flag = segmentIntersection(a, b, c, d, p);
    cout << abs(flag) << '\n';

    if (flag == 1)
        cout << setprecision(10) << p.x << " " << p.y << '\n';
}
