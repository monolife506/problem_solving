#include <iostream>
#include <vector>
using namespace std;

int N, M, ans = -1;
bool P[11][11];

void backtracking(int cur, int curSize, vector<bool> v)
{
    bool flag = true;
    for (size_t i = 1; i <= N; i++) {
        if (!v[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        ans = (ans == -1) ? curSize : min(ans, curSize);
        return;
    }

    if (cur > M)
        return;

    vector<bool> next(N + 1, false);
    backtracking(cur + 1, curSize, v);
    for (size_t i = 1; i <= N; i++)
        next[i] = P[cur][i] | v[i];
    backtracking(cur + 1, curSize + 1, next);
}

int main()
{
    cin >> N >> M;
    for (size_t i = 1; i <= M; i++) {
        int problemCnt, problemNum;
        cin >> problemCnt;
        for (size_t j = 0; j < problemCnt; j++) {
            cin >> problemNum;
            P[i][problemNum] = true;
        }
    }

    backtracking(1, 0, vector<bool>(N + 1, false));
    cout << ans;
}