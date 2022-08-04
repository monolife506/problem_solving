#include <iostream>
#include <vector>
using namespace std;

int N, T;
vector<int> A, B, C, D, E;

int f(int t)
{
    int ret = t + E[0];
    for (int i = 1; i <= N; ++i) // ret 시점에 i번째 횡단보도에 도착
    {
        if (ret < C[i])
            ret = C[i];

        if ((ret - C[i]) % A[i] >= 0 && (ret - C[i]) % A[i] <= B[i] - D[i])
            ret += D[i];
        else
            ret += (A[i] - ((ret - C[i]) % A[i])) + D[i];

        ret += E[i];
    }

    return ret;
}

bool binary_search(int target)
{
    int l = 0;
    int r = 1e9;
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (f(mid) == target)
            return true;
        else if (f(mid) > target)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc)
    {
        cin >> N >> T;

        A.resize(N + 1);
        B.resize(N + 1);
        C.resize(N + 1);
        D.resize(N + 1);
        E.resize(N + 1);

        for (int i = 1; i <= N; ++i)
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        for (int i = 0; i <= N; ++i)
            cin >> E[i];

        cout << (binary_search(T) ? "YES" : "NO") << '\n';
    }
}

/*

C[i] + nA[i] <= t
nA[i] <= t - C[i] <= nA[i] + B[i] - D[i]

t + D[i] <= C[i] + nA[i] + B[i]
t - C[i] <= nA[i] + B[i] - D[i]

*/