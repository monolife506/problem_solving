#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, P;
    cin >> N >> M >> P;

    int cnt = 0;
    for (int i = M; i <= N; i += P)
        cnt++;

    cout << cnt << '\n';
}