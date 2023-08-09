#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<int> T(N);
    for (int i = 0; i < N; ++i)
        cin >> T[i];

    for (int i = 1; i < N; ++i)
    {
        if (T[i] - T[i - 1] <= D)
        {
            cout << T[i] << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}