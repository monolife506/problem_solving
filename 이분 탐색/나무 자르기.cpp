// 2805번: 나무 자르기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long getCut(const vector<int> &v, int H)
{
    long long val = 0;
    for (const int item : v)
    {
        if (item > H)
            val += (item - H);
    }
    return val;
}

// 잘린 나무의 높이가 M 이하인 최소 높이
// 검색 범위 : 0 ~ (최대 나무의 높이 - 1)
int search(const vector<int> &v, int left, int right, int M, int max_tree)
{
    int middle = (left + right) / 2;
    long long total_h = getCut(v, middle);

    if (total_h < M)
        return search(v, left, middle - 1, M, max_tree);
    else
    {
        if (middle == max_tree - 1)
            return middle;
        else if (getCut(v, middle + 1) < M)
            return middle;
        else
            return search(v, middle + 1, right, M, max_tree);
    }
}

int main()
{
    size_t N, M;
    cin >> N >> M;
    vector<int> tree(N);
    for (int &H : tree)
        cin >> H;
    sort(tree.begin(), tree.end());
    cout << search(tree, 0, tree[N - 1] - 1, M, tree[N - 1]);
}
