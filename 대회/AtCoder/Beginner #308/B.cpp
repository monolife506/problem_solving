#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> C(N);
    for (int i = 0; i < N; ++i)
        cin >> C[i];

    vector<string> D(M);
    for (int i = 0; i < M; ++i)
        cin >> D[i];

    int p;
    cin >> p;
    map<string, int> prices;
    for (int i = 0; i < M; ++i)
    {
        int num;
        cin >> num;
        prices[D[i]] = num;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (prices.find(C[i]) == prices.end())
            ans += p;
        else
            ans += prices[C[i]];
    }

    cout << ans << '\n';
}