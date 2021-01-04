#include <iostream>
using namespace std;

int N, ans = 10000;
int G[10][10];
bool used[10][10];

const int dx[5] = { 1, -1, 0, 0, 0 };
const int dy[5] = { 0, 0, 1, -1, 0 };

void marking(int sum, int cnt)
{
    if (cnt == 3) {
        ans = min(ans, sum);
        return;
    }

    int value = 0;
    bool flag = true;

    for (size_t cur = 0; cur < (N - 2) * (N - 2); cur++) {
        int x = (cur / (N - 2)) + 1;
        int y = (cur % (N - 2)) + 1;

        value = 0;
        flag = true;

        for (size_t i = 0; i < 5; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (used[nextX][nextY]) {
                flag = false;
                break;
            }
        }

        if (!flag)
            continue;

        for (size_t i = 0; i < 5; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            used[nextX][nextY] = true;
            value += G[nextX][nextY];
        }

        marking(sum + value, cnt + 1);

        for (size_t i = 0; i < 5; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            used[nextX][nextY] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }

    marking(0, 0);
    cout << ans;
}