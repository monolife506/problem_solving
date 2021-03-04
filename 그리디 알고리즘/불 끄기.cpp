#include <iostream>
using namespace std;
const int MAX = 987654321;

char buffer[11];
int arr[11];
int ans = MAX;

void dfs(int line, int upper, int cur, int cnt)
{
    if (line == 10) {
        if (upper == 0)
            ans = min(ans, cnt);
        return;
    }

    int lower = arr[line + 1];

    for (int i = 0; i < 10; i++) {

        if (!(upper & (1 << i)))
            continue;

        cur ^= (1 << i);
        upper ^= (1 << i);
        lower ^= (1 << i);
        if (i != 0)
            cur ^= (1 << (i - 1));
        if (i != 9)
            cur ^= (1 << (i + 1));

        cnt++;
    }

    if (upper != 0)
        return;

    dfs(line + 1, cur, lower, cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++) {
        cin >> buffer;
        for (int j = 0; j < 10; j++) {
            if (buffer[j] == 'O')
                arr[i] |= (1 << j);
        }
    }

    for (int i = 0; i < 1024; i++) {

        int cnt = 0;
        int cur = arr[0], lower = arr[1];

        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                cnt++;
                cur ^= (1 << j);
                lower ^= (1 << j);
                if (j != 0)
                    cur ^= (1 << (j - 1));
                if (j != 9)
                    cur ^= (1 << (j + 1));
            }
        }

        dfs(1, cur, lower, cnt);
    }

    cout << ((ans == MAX) ? -1 : ans) << '\n';
}