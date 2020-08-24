// 15663번: N과 M (12)

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[8];
int ans[8];

void dfs(int cnt, int min)
{
    if (cnt == M)
    {
        for (size_t i = 0; i < M; i++)
            cout << ans[i] << " ";

        cout << '\n';
        return;
    }

    int before = -1;
    for (size_t i = min; i < N; i++)
    {
        if (before == nums[i])
            continue;

        before = ans[cnt] = nums[i];
        dfs(cnt + 1, i);
    }
}

int main()
{
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums, nums + N);
    dfs(0, 0);
}