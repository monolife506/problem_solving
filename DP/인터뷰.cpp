#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int A[100001];
ll cache[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, Q;
    cin >> N >> K >> Q;

    int idx[4] = {};
    for (int i = 1; i <= N; ++i)
    {
        cin >> A[i];
        idx[A[i]] = i;
        cache[i] = cache[i - 1] + (i - idx[K]);
    }

    for (int i = 0; i < Q; ++i)
    {
        int X;
        cin >> X;

        cout << cache[X] << '\n';
    }
}