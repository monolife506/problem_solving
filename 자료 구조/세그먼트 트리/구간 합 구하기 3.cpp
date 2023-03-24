#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree2D
{
private:
    int n;
    vector<vector<int>> v;

    int init1D(int row_idx, int idx, int row, int lo, int hi, vector<vector<int>> &val)
    {
        if (lo == hi)
            return v[row_idx][idx] = val[row][lo];

        int mid = (lo + hi) / 2;
        int left = init1D(row_idx, idx * 2, row, lo, mid, val);
        int right = init1D(row_idx, idx * 2 + 1, row, mid + 1, hi, val);
        return v[row_idx][idx] = left + right;
    }

    void init2D(int idx, int lo, int hi, vector<vector<int>> &val)
    {
        if (lo == hi)
        {
            init1D(idx, 1, lo, 0, n - 1, val);
            return;
        }

        int mid = (lo + hi) / 2;
        init2D(idx * 2, lo, mid, val);
        init2D(idx * 2 + 1, mid + 1, hi, val);

        for (size_t i = 1; i < v.size(); i++)
            v[idx][i] = v[idx * 2][i] + v[idx * 2 + 1][i];
    }

    int query1D(int row_idx, int idx, int lo, int hi, int L, int R)
    {
        if (L > hi || R < lo)
            return 0;
        if (L <= lo && hi <= R)
            return v[row_idx][idx];

        int mid = (lo + hi) / 2;
        int left = query1D(row_idx, idx * 2, lo, mid, L, R);
        int right = query1D(row_idx, idx * 2 + 1, mid + 1, hi, L, R);
        return left + right;
    }

    int query2D(int idx, int lo, int hi, int x1, int x2, int y1, int y2)
    {
        if (y1 > hi || y2 < lo)
            return 0;
        if (y1 <= lo && hi <= y2)
            return query1D(idx, 1, 0, n - 1, x1, x2);

        int mid = (lo + hi) / 2;
        int left = query2D(idx * 2, lo, mid, x1, x2, y1, y2);
        int right = query2D(idx * 2 + 1, mid + 1, hi, x1, x2, y1, y2);
        return left + right;
    }

    int update1D(int row_idx, int idx, int lo, int hi, int x, int c)
    {
        if (x < lo || x > hi)
            return v[row_idx][idx];
        if (lo == hi)
            return v[row_idx][idx] = c;

        int mid = (lo + hi) / 2;
        int left = update1D(row_idx, idx * 2, lo, mid, x, c);
        int right = update1D(row_idx, idx * 2 + 1, mid + 1, hi, x, c);
        return v[row_idx][idx] = left + right;
    }

    void update2D(int idx, int lo, int hi, int x, int y, int c)
    {
        if (y < lo || y > hi)
            return;

        if (lo == hi)
        {
            update1D(idx, 1, 0, n - 1, x, c);
            return;
        }

        int mid = (lo + hi) / 2;
        update2D(idx * 2, lo, mid, x, y, c);
        update2D(idx * 2 + 1, mid + 1, hi, x, y, c);

        for (size_t i = 1; i < v.size(); i++)
            v[idx][i] = v[idx * 2][i] + v[idx * 2 + 1][i];
    }

public:
    SegmentTree2D(int n, vector<vector<int>> &val) : n(n)
    {
        int h = (int)ceil(log2(n));
        int v_size = (1 << (h + 1));
        v.resize(v_size + 1, vector<int>(v_size + 1));
        init2D(1, 0, n - 1, val);
    }

    int query(int x1, int y1, int x2, int y2)
    {
        return query2D(1, 0, n - 1, x1, x2, y1, y2);
    }

    void update(int x, int y, int c)
    {
        update2D(1, 0, n - 1, x, y, c);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> val(N, vector<int>(N));
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            cin >> val[i][j];

    SegmentTree2D tree(N, val);
    for (size_t i = 0; i < M; i++)
    {
        int w;
        cin >> w;

        if (w == 0)
        {
            int x, y, c;
            cin >> x >> y >> c;
            tree.update(y - 1, x - 1, c);
        }
        else // w == 1
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << tree.query(y1 - 1, x1 - 1, y2 - 1, x2 - 1) << '\n';
        }
    }
}