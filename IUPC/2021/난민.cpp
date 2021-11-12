#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

pair<int, ll> getAns(int x, int y)
{
    // 중앙값보다 작은 값들에 대한 최대 힙
    static priority_queue<int> max_pq;
    static ll max_pq_sum = 0;
    // 중앙값보다 큰 값들에 대한 최소 힙
    static priority_queue<int, vector<int>, greater<int>> min_pq;
    static ll min_pq_sum = 0;

    static ll x_sum = 0;

    int mid;
    ll y_sum = 0;

    // 힙에 숫자 push

    // 두 힙의 크기 차이를 하나 이하로 줄이기
    if (abs(max_pq.size() - min_pq.size()) == 2)
    {
        if (max_pq.size() > min_pq.size())
        {
            max_pq_sum -= max_pq.top();
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else
        {
            min_pq_sum -= min_pq.top();
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }

    // 중앙값 계산 및 x_sum, y_sum 계산
    if (max_pq.size() == min_pq.size())
    {
        if (max_pq.top() > min_pq.top())
        {
            mid = min_pq.top();
            y_sum += max_pq_sum;
            y_sum -= min_pq_sum - mid;
        }
        else
        {
            mid = max_pq.top();
        }
    }
    else // diff == 1
    {
        if (max_pq.size() > min_pq.size())
        {
            mid = max_pq.top();
        }
        else
        {
            mid = min_pq.top();
        }
    }

    x_sum += abs(x);
    return make_pair(mid, x_sum + y_sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
    }
}