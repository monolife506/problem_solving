#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int pyramid[1001][1001], target[2][1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
            cin >> pyramid[i][j];
    }

    int st[2] = {pyramid[1][1], pyramid[1][1]};
    for (int i = 1; i <= N; ++i)
    {
        int num[2] = {st[0], st[1]};
        for (int j = 1; j <= i; ++j)
        {
            target[0][i][j] = num[0];
            target[1][i][j] = num[1];
            num[0] = (num[0] + 1) % 3;
            num[1] = (num[1] + 2) % 3;
        }

        st[0] = (st[0] + 1) % 3;
        st[1] = (st[1] + 2) % 3;
    }

    int ans = INF;
    for (int s = 0; s < 2; ++s)
    {
        int sum = 0;
        for (int i = 1; i <= N; ++i)
        {
            vector<vector<int>> cnt(2, vector<int>(3, 0));
            vector<vector<int>> diff(3, vector<int>(3, 0));
            for (int j = 1; j <= i; ++j)
            {
                cnt[0][pyramid[i][j]]++;
                cnt[1][target[s][i][j]]++;
                diff[target[s][i][j]][pyramid[i][j]]++;
            }

            if (cnt[0][0] != cnt[1][0] || cnt[0][1] != cnt[1][1] || cnt[0][2] != cnt[1][2])
                break;

            int tmp;

            tmp = min(diff[0][1], diff[1][0]);
            diff[0][1] -= tmp;
            diff[1][0] -= tmp;
            sum += tmp;

            tmp = min(diff[1][2], diff[2][1]);
            diff[1][2] -= tmp;
            diff[2][1] -= tmp;
            sum += tmp;

            tmp = min(diff[0][2], diff[2][0]);
            diff[0][2] -= tmp;
            diff[2][0] -= tmp;
            sum += tmp;

            sum += diff[0][1] * 2;
            sum += diff[1][0] * 2;

            if (i == N)
                ans = min(ans, sum);
        }
    }

    cout << (ans != INF ? ans : -1) << '\n';
}

/*

0
2 1
1 0 2
0 2 1 0

0 -> 1 1
1 -> 0 1
1 -> 2 2
2 -> 0 1


6
0
1 2
2 0 1
0 1 2 0
1 2 0 1 2
0 1 2 0 1 2

0
1 2
2 0 1
0 1 2 0
1 2 0 1 2
2 0 1 2 0 1 -> 4
0 1 2 0 1 2

2 -> 0 3
0 -> 1 3
1 -> 2 3

0
2 1 -> 1
1 0 2 -> 2
0 2 1 0 -> 1
2 1 0 2 1 -> 2
1 0 2 1 0 2 -> 2
0 1 2 0 1 2

*/