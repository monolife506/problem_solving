#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

struct Line
{
    P s;
    P e;
    ll w, c;
};

int ccw(const P &A, const P &B, const P &C)
{
    ll cross = (B.first - A.first) * (C.second - A.second);
    cross -= (B.second - A.second) * (C.first - A.first);
    return (cross > 0) - (cross < 0);
}

bool checkcross(Line &A, Line &B)
{
    int flag1 = ccw(A.s, A.e, B.s) * ccw(A.s, A.e, B.e);
    int flag2 = ccw(B.s, B.e, A.s) * ccw(B.s, B.e, A.e);

    if (flag1 == 0 && flag2 == 0)
    {
        if (A.s > A.e)
            swap(A.s, A.e);
        if (B.s > B.e)
            swap(B.s, B.e);

        return (B.s <= A.e) && (A.s <= B.e);
    }

    return (flag1 <= 0) && (flag2 <= 0);
}

Line p[2500];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> p[i].s.first >> p[i].s.second >> p[i].e.first >> p[i].e.second >> p[i].w;

    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (checkcross(p[i], p[j]))
            {
                p[i].c++;
                p[j].c++;
            }
        }
    }

    sort(p, p + N, [](Line &lhs, Line &rhs) -> bool
         { return lhs.w < rhs.w; });

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int m = 1;
        for (int j = i + 1; j < N; j++)
        {
            if (checkcross(p[i], p[j]))
            {
                p[j].c--;
                ++m;
            }
        }

        ans += m * p[i].w;
    }

    cout << ans << '\n';
}