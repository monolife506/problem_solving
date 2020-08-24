// 15663번: N과 M (9)

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[8];
int ans[8];
bool used[8];

void dfs(int cnt)
{
    if (cnt == M)
    {
        for (size_t i = 0; i < M; i++)
            cout << ans[i] << " ";

        cout << '\n';
        return;
    }

    int before = -1;
    for (size_t i = 0; i < N; i++)
    {
        if (!used[i])
        {
            if (before == nums[i])
                continue;

            used[i] = true;
            ans[cnt] = nums[i];
            before = nums[i];
            dfs(cnt + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
        cin >> nums[i];

    sort(nums, nums + N);
    dfs(0);
}