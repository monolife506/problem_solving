// 6549번: 히스토그램에서 가장 큰 직사각형

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef unsigned long long ll;

size_t N;
int init(vector<ll> &H, vector<int> &tree, int index, int start, int end)
{
    if (start == end)
        tree[index] = start;
    else
    {
        int left_index = init(H, tree, index * 2, start, (start + end) / 2);
        int right_index = init(H, tree, index * 2 + 1, (start + end) / 2 + 1, end);
        tree[index] = (H[left_index] >= H[right_index]) ? right_index : left_index;
    }
    return tree[index];
}

int query(vector<ll> &H, vector<int> &tree, int index, int start, int end, int left, int right)
{
    if (end < left || start > right)
        return -1;
    if (left <= start && end <= right)
        return tree[index];

    int left_index = query(H, tree, index * 2, start, (start + end) / 2, left, right);
    int right_index = query(H, tree, index * 2 + 1, (start + end) / 2 + 1, end, left, right);

    if (left_index == -1 || right_index == -1)
        return (left_index != -1) ? left_index : right_index;
    return (H[left_index] >= H[right_index]) ? right_index : left_index;
}

ll part_sum(vector<ll> &H, vector<int> &tree, int start, int end)
{
    int M = query(H, tree, 1, 0, N - 1, start, end);
    ll rec_area = (end - start + 1) * H[M];

    if (start <= M - 1)
    {
        ll temp = part_sum(H, tree, start, M - 1);
        if (temp > rec_area)
            rec_area = temp;
    }
    if (end >= M + 1)
    {
        ll temp = part_sum(H, tree, M + 1, end);
        if (temp > rec_area)
            rec_area = temp;
    }
    return rec_area;
}

int main()
{
    cin >> N;
    while (N != 0)
    {
        vector<ll> H(N);
        for (size_t i = 0; i < N; i++)
            cin >> H[i];

        int height = (int)ceil(log2(N));
        int tree_size = (int)pow(2, height + 1);
        vector<int> tree(tree_size);
        init(H, tree, 1, 0, N - 1);
        cout << part_sum(H, tree, 0, N - 1) << '\n';

        H.clear();
        tree.clear();
        cin >> N;
    }
}

// 세그먼트 트리: https://www.acmicpc.net/blog/view/9
