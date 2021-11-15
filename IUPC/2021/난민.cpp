#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

pair<int, ll> getAns(int x, int y, ll x_sum)
{
    // 중앙값보다 작은 값들에 대한 최대 힙
    static priority_queue<int> max_pq;
    static ll max_pq_sum = 0;
    // 중앙값보다 큰 값들에 대한 최소 힙
    static priority_queue<int, vector<int>, greater<int>> min_pq;
    static ll min_pq_sum = 0;

    // 힙에 숫자 push
    if (max_pq.empty() || max_pq.top() >= y)
    {
        max_pq.push(y);
        max_pq_sum += y;
    }
    else
    {
        min_pq.push(y);
        min_pq_sum += y;
    }

    // 두 힙의 크기 차이를 하나 이하로 줄이기
    if (abs((ll)max_pq.size() - (ll)min_pq.size()) == 2)
    {
        if (max_pq.size() > min_pq.size())
        {
            max_pq_sum -= max_pq.top();
            min_pq_sum += max_pq.top();
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else
        {
            min_pq_sum -= min_pq.top();
            max_pq_sum += min_pq.top();
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }

    // 중앙값 계산 및 y_sum 계산
    int mid;
    ll y_sum = 0;

    if (!min_pq.empty())
        y_sum += min_pq_sum - min_pq.top();
    if (!max_pq.empty())
        y_sum -= max_pq_sum - max_pq.top();

    if (max_pq.size() == min_pq.size())
    {
        if (max_pq.top() > min_pq.top())
        {
            mid = min_pq.top();
            y_sum += max_pq.top();
        }
        else
        {
            mid = max_pq.top();
            y_sum += min_pq.top();
        }

        y_sum -= mid;
    }
    else // diff == 1
    {
        if (max_pq.size() > min_pq.size())
        {
            mid = max_pq.top();
            if (!min_pq.empty())
                y_sum += min_pq.top();
        }
        else
        {
            mid = min_pq.top();
            if (!max_pq.empty())
                y_sum -= max_pq.top();
        }
    }

    return make_pair(mid, x_sum + y_sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    ll x_sum = 0;

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        x_sum += abs(x);

        pair<int, ll> ans = getAns(x, y, x_sum);
        cout << ans.first << " " << ans.second << '\n';
    }
}