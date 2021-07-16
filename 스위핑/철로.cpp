#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

P arr[100001];

struct cmp {
    bool operator()(P& a, P& b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first > b.first;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    int lo, hi, ans = 0;
    priority_queue<P, vector<P>, cmp> pq; // 시작점 순 정렬

    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        if (arr[i].first < arr[i].second) {
            int tmp = arr[i].second;
            arr[i].second = arr[i].first;
            arr[i].first = tmp;
        }
    }
    cin >> d;

    lo = -1e8;
    hi = lo + d;
    sort(arr, arr + n); // 끝점 순 정렬
    for (int i = 0; i < n; i++) {
        if (arr[i].first - arr[i].second > d)
            continue;
        if (arr[i].first > hi) {
            hi = arr[i].first;
            lo = hi - d;
            while (!pq.empty() && pq.top().second < lo)
                pq.pop();
        }

        pq.push(arr[i]);
        ans = max(ans, (int)pq.size());
    }

    cout << ans << '\n';
}

/*
0 1
-2 2
-1 3
0 3
4

1 4
1 4
3 4
2 5
3
*/
