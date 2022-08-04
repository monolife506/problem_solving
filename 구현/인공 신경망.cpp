#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N, M, Q, W[2000], B[2001], A[2001];

vector<pair<int, int>> perceptron[2000];
ll coefficient[2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> Q;
    for (int i = 0; i < M; ++i)
    {
        int C;
        cin >> C;

        perceptron[i].resize(C + 1);
        for (int j = 1; j <= C; ++j)
            cin >> perceptron[i][j].first;
        for (int j = 1; j <= C; ++j)
            cin >> perceptron[i][j].second;

        cin >> B[i];
    }

    for (int i = 0; i < M; ++i)
        cin >> W[i];

    cin >> coefficient[0];
    for (int i = 0; i < M; ++i)
    {
        for (pair<int, int> &p : perceptron[i])
            coefficient[p.first] += p.second * W[i];
        coefficient[0] += B[i] * W[i];
    }

    for (int q = 0; q < Q; ++q)
    {
        ll ans = 0;
        for (int i = 1; i <= N; ++i)
        {
            cin >> A[i];
            ans += coefficient[i] * A[i];
        }

        cout << ans + coefficient[0] << '\n';
    }
}

/*

10(a + 2b + 7)
20(3b + 4c + 8)
30(5d + 6e + 9)
+ 100

*/