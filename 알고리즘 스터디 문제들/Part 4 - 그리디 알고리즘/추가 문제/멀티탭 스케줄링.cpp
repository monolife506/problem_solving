// 의도적으로 STL set을 이용하지 않은 풀이입니다.
// STL set을 이용하면 훨씬 간편하게 풀이가 가능합니다.

// 플러그가 다 찬 경우 빼는 기준
// 하나라도 더 꽂을 일이 없는 플러그가 있으면 => 그걸 뺌
// 세개 다 나중에 다시 꽂아야 하는 플러그라면 => 가장 뒤에 다시 꽂아야 하는걸 뺌

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    size_t N, K;
    cin >> N >> K;

    vector<int> sc(K); // 쓰는 기기의 스케줄
    for (size_t i = 0; i < K; i++)
        cin >> sc[i];

    int ans = 0; // 플러그를 빼는 횟수
    int cur = N; // 현재 남은 구멍의 개수
    vector<int> used(K + 1, 0);

    for (size_t i = 0; i < K; i++)
    {
        if (used[sc[i]] == 0)
        {
            if (cur == 0)
            {
                int cnt = 0;
                int idx = 0;
                for (size_t j = i + 1; j < K; j++)
                {
                    if (used[sc[j]] == 1)
                    {
                        used[sc[j]] = 2;
                        cnt++;
                        idx = j;
                    }
                }

                if (cnt == N)
                    used[sc[idx]] = 0;
                else
                    *find(used.begin(), used.end(), 1) = 0;

                replace(used.begin(), used.end(), 2, 1);
                ans++;
            }
            else
                cur--;

            used[sc[i]] = 1;
        }
    }

    cout << ans;
}
