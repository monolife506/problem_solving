#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

struct Line
{
    P s; // 시작점
    P e; // 끝점
    int root = -1;
};

int N;
Line arr[3000];

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

int getRoot(int N)
{
    if (arr[N].root < 0)
        return N;
    return arr[N].root = getRoot(arr[N].root);
}

int getSize(int N)
{
    return abs(arr[getRoot(N)].root);
}

void merge(int A, int B)
{
    int rootA = getRoot(A);
    int rootB = getRoot(B);
    if (rootA != rootB && checkcross(arr[A], arr[B]))
    {
        arr[rootB].root += arr[rootA].root;
        arr[rootA].root = rootB;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i].s.first >> arr[i].s.second >>
            arr[i].e.first >> arr[i].e.second;
    }

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            merge(i, j);

    int groupCnt = 0;
    int maxCnt = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (i == getRoot(i))
        {
            groupCnt++;
            maxCnt = max(maxCnt, getSize(i));
        }
    }

    cout << groupCnt << '\n';
    cout << maxCnt;
}