#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

struct Shark
{
    int sz, speed, iq;
    Shark(int sz = 0, int speed = 0, int iq = 0)
        : sz(sz), speed(speed), iq(iq) {}
};

// follow strict weak ordering
bool cmp(const Shark &lhs, const Shark &rhs)
{
    if (lhs.sz == rhs.sz && lhs.speed == rhs.speed && lhs.sz == rhs.speed)
        return false;
    return (lhs.sz <= rhs.sz && lhs.speed <= rhs.speed && lhs.sz <= rhs.speed);
}

Shark arr[50];
vector<int> graph[100];
int matched[50];
bool visited[100];

bool match(int cur)
{
    if (visited[cur])
        return false;

    visited[cur] = true;
    for (int nxt : graph[cur])
    {
        if (matched[nxt] == -1 || match(matched[nxt]))
        {
            matched[nxt] = cur;
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i].sz >> arr[i].speed >> arr[i].iq;

    sort(arr, arr + N, cmp);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[i].sz == arr[j].sz && arr[i].speed == arr[j].speed && arr[i].iq == arr[j].iq)
            {
                if (i < j)
                {
                    graph[i * 2].push_back(j);
                    graph[i * 2 + 1].push_back(j);
                }

                continue;
            }
            else if (arr[i].sz >= arr[j].sz && arr[i].speed >= arr[j].speed && arr[i].iq >= arr[j].iq)
            {
                graph[i * 2].push_back(j);
                graph[i * 2 + 1].push_back(j);
            }
        }
    }

    int match_cnt = 0;
    memset(matched, -1, sizeof(matched));
    for (int i = 0; i < N * 2; ++i)
    {
        memset(visited, false, sizeof(visited));
        match_cnt += match(i);
    }

    cout << N - match_cnt << '\n';
}