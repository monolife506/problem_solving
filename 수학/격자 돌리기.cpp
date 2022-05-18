#include <iostream>
using namespace std;
typedef pair<int, int> P;

const int MAX_N = 2000;

int N, M, arr[MAX_N + 1][MAX_N + 1];
int num[MAX_N + 1][MAX_N + 1], cnt[MAX_N + 1];

P get_idx(int i, int j) // find real idx
{
    int len = N - 2 * (num[i][j] - 1);
    int offset;

    if (i >= j)
        offset = (i - num[i][j]) + (j - num[i][j]);
    else
        offset = (4 * len - 4) - ((i - num[i][j]) + (j - num[i][j]));

    offset += cnt[num[i][j]];
    offset %= (4 * len - 4);

    if (offset < len)
        return {num[i][j] + offset, num[i][j]};
    else if (offset < len * 2 - 1)
        return {num[i][j] + (len - 1), num[i][j] + (offset - (len - 1))};
    else if (offset < len * 3 - 2)
        return {(num[i][j] + (len - 1)) - (offset - (len * 2 - 2)), num[i][j] + (len - 1)};
    else
        return {num[i][j], (num[i][j] + (len - 1)) - (offset - (len * 3 - 3))};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> arr[i][j];
            num[i][j] = min(((i <= N / 2) ? i : (N + 1) - i),
                            ((j <= N / 2) ? j : (N + 1) - j));
        }
    }

    for (int query_i = 0; query_i < M; ++query_i)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int a, b;
            cin >> a >> b;
            cnt[a] += b;
            cnt[a] %= 4 * (N - 2 * (a - 1)) - 4;
        }
        else if (q == 2)
        {
            int c, d;
            cin >> c >> d;

            P idx[4] = {get_idx(c, d), get_idx(c, d + 1),
                        get_idx(c + 1, d + 1), get_idx(c + 1, d)};

            int val[4];
            for (int i = 0; i < 4; ++i)
                val[i] = arr[idx[i].first][idx[i].second];
            for (int i = 0; i < 4; ++i)
                arr[idx[i].first][idx[i].second] = val[(i + 3) % 4];
        }
        else
        {
            int e, f;
            cin >> e >> f;

            P idx = get_idx(e, f);
            cout << arr[idx.first][idx.second] << '\n';
        }
    }
}

/*

1 2
3 4

3 1
4 2

4 3
2 1

2 4
1 3


*/