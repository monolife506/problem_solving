#include <cstring>
#include <iostream>
using namespace std;

struct rectangle
{
    int max_x, max_y, min_x, min_y;
};

int root[1001];
rectangle arr[1001];

int find(int n)
{
    if (root[n] == -1)
        return n;
    return root[n] = find(root[n]);
}

void merge(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);
    if (root_a != root_b)
        root[root_b] = root_a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(root, -1, sizeof(root));

    int N, ans = 0;
    bool is_crossing_origin = false; // (0, 0)을 지나는가

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[i].max_x = max(x1, x2);
        arr[i].min_x = min(x1, x2);
        arr[i].max_y = max(y1, y2);
        arr[i].min_y = min(y1, y2);

        if ((arr[i].min_x == 0 || arr[i].max_x == 0) && arr[i].min_y <= 0 && arr[i].max_y >= 0)
            is_crossing_origin = true;
        else if ((arr[i].min_y == 0 || arr[i].max_y == 0) && arr[i].min_x <= 0 && arr[i].max_x >= 0)
            is_crossing_origin = true;
    }

    for (size_t i = 0; i + 1 < N; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            bool outer_x = (arr[i].min_x > arr[j].max_x || arr[i].max_x < arr[j].min_x);
            bool outer_y = (arr[i].min_y > arr[j].max_y || arr[i].max_y < arr[j].min_y);
            bool inner_x_i = (arr[j].min_x < arr[i].min_x && arr[j].max_x > arr[i].max_x);
            bool inner_y_i = (arr[j].min_y < arr[i].min_y && arr[j].max_y > arr[i].max_y);
            bool inner_x_j = (arr[i].min_x < arr[j].min_x && arr[i].max_x > arr[j].max_x);
            bool inner_y_j = (arr[i].min_y < arr[j].min_y && arr[i].max_y > arr[j].max_y);
            if (outer_x || outer_y || (inner_x_i && inner_y_i) || (inner_x_j && inner_y_j))
                continue;

            merge(i, j);
        }
    }

    for (size_t i = 0; i < N; i++)
        if (root[i] == -1)
            ans++;

    cout << (is_crossing_origin ? ans - 1 : ans) << '\n';
}