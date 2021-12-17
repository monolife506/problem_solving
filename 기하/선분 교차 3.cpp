#include <iostream>
using namespace std;

struct vector2
{
    double x, y;
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    bool operator==(const vector2 &rhs) const { return x == rhs.x && y == rhs.y; }
    bool operator<(const vector2 &rhs) const { return x != rhs.x ? x < rhs.x : y < rhs.y; }

    vector2 operator+(const vector2 &rhs) const { return vector2(x + rhs.x, y + rhs.y); }
    vector2 operator-(const vector2 &rhs) const { return vector2(x - rhs.x, y - rhs.y); }
    vector2 operator*(double rhs) const { return vector2(x * rhs, y * rhs); }

    double dot(const vector2 &rhs) const { return x * rhs.x + y * rhs.y; }
    double cross(const vector2 &rhs) const { return x * rhs.y - y * rhs.x; }
};

bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p);
int parallelSegmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p);
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b);
int segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector2 a, b, c, d, p;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
}

// (a, b)를 포함하는 직선과 (c, d)를 포함하는 직선이 교차하는지 확인하고 교점을 p에 반환
// false일 경우 두 직선의 기울기는 같음
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p)
{
}

// 선분 (a, b), (c, d)의 기울기가 같을 때 교점이 1개인 경우 교점을 p에 반환
// 0: 교점 없음, 1: 교점 1개, -1: 교점이 무한히 많음
int parallelSegmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p)
{
}

// 선분 (a, b)를 대각선으로 하는 직사각형 내에 점 p가 존재하는지 확인
// 직선을 구할 때 p는 대각선을 일부로 하는 직선 위 점이므로 이 직사각형 내 존재하면 p는 (a, b) 위에 존재함
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b)
{
}

// 선분 (a, b), (c, d)이 교차하는지 확인하고 교점이 1개인 경우 교점을 p에 반환
// 0: 교점 없음, 1: 교점 1개, -1: 교점이 무한히 많음
int segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2 &p)
{
    if (!lineIntersection(a, b, c, d, p))
        return parallelSegmentIntersection(a, b, c, d, p);
}
