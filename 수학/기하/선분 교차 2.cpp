// 17387번: 선분 교차 2

#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int ccw(const P &A, const P &B, const P &C)
{
    ll cross = (B.first - A.first) * (C.second - A.second);
    cross -= (B.second - A.second) * (C.first - A.first);
    return (cross > 0) - (cross < 0);
}

bool checkcross(P A1, P A2, P B1, P B2)
{
    int flag1 = ccw(A1, A2, B1) * ccw(A1, A2, B2);
    int flag2 = ccw(B1, B2, A1) * ccw(B1, B2, A2);

    if (flag1 == 0 && flag2 == 0)
    {
        if (A1 > A2)
            swap(A1, A2);
        if (B1 > B2)
            swap(B1, B2);

        return (B1 <= A2) && (A1 <= B2);
    }

    return (flag1 <= 0) && (flag2 <= 0);
}

int main()
{
    P p[4];
    for (size_t i = 0; i < 4; i++)
        cin >> p[i].first >> p[i].second;

    cout << checkcross(p[0], p[1], p[2], p[3]);
}

// A C D B
// A C B D
// C A D B
// C A B D