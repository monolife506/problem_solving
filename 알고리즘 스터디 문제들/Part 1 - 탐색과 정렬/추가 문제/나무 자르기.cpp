#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long getHeight(int H, const vector<int> &tree)
{
    long long sum = 0;
    for (size_t i = 0; i < tree.size(); i++)
    {
        if (tree[i] > H)
            sum += (tree[i] - H);
    }

    return sum;
}

long long ans(int target, const vector<int> &tree)
{
    long long left = 0;
    long long right = 1'000'000'000; // H는 나무의 최대 높이보단 작을 것이다.
    long long mid;
    long long ans;

    while (left <= right)
    {
        mid = (left + right) / 2;

        long long curHeight = getHeight(mid, tree);

        if (curHeight >= target)
        {
            ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return ans;
}

int main()
{
    size_t N, M;
    cin >> N >> M;

    vector<int> tree(N);
    for (size_t i = 0; i < N; i++)
        cin >> tree[i];

    sort(tree.begin(), tree.end());
    cout << ans(M, tree);
}