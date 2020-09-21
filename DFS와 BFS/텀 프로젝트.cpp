// 9466번: 텀 프로젝트
// 사이클 찾기 문제

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, cnt;
int pick[100001];
int isCycle[100001];
bool visited[100001];
vector<int> cycleList;

void getCycle(int cur)
{
    cycleList.push_back(cur);
    visited[cur] = true;

    if (visited[pick[cur]])
    {
        int flag = -1;
        if (isCycle[pick[cur]] == 0)
            flag = 1;

        while (!cycleList.empty())
        {
            isCycle[cycleList.back()] = flag;
            if (cycleList.back() == pick[cur])
                flag = -1;
            cycleList.pop_back();
        }

        return;
    }

    getCycle(pick[cur]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        cnt = 0;
        memset(isCycle, false, sizeof(isCycle));
        memset(visited, false, sizeof(visited));

        cin >> N;
        for (size_t i = 1; i <= N; i++)
            cin >> pick[i];
        for (size_t i = 1; i <= N; i++)
        {
            if (!visited[i])
                getCycle(i);
        }
        for (size_t i = 1; i <= N; i++)
        {
            if (isCycle[i] == -1)
                cnt++;
        }
        cout << cnt << '\n';
    }
}