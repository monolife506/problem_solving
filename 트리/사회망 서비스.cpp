#include <iostream>
#include <vector>
using namespace std;
constexpr int MAX = 1'000'000;

vector<int> tree[1000001];

// dp[0][i]: 자신이 얼리어답터가 아닌 경우 i를 루트로 하는 트리의 얼리어답터 수
// dp[1][i]: 자신이 얼리어답터인 경우 i를 루트로 하는 트리의 얼리어답터 수
int dp[2][1000001];

void dfs(int parent, int cur)
{
    dp[0][cur] = 0;
    dp[1][cur] = 1;

    if (tree[cur].size() == 1 && parent == tree[cur][0])
        return;

    for (int next : tree[cur]) {
        if (next != parent) {
            dfs(cur, next);
            dp[0][cur] += dp[1][next];
            dp[1][cur] += min(dp[0][next], dp[1][next]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (size_t i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(-1, 1);
    cout << min(dp[0][1], dp[1][1]) << '\n';
}

//      1
//    2    3
//   4    5 6
// 7 8 9