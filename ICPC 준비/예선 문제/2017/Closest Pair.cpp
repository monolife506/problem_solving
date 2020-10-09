#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, bool> P;

int n, m, x;
int py, qy;
int cnt, dist = 400000000;
vector<P> num;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> py >> qy;
    for (size_t i = 0; i < n; i++)
    {
        cin >> x;
        num.push_back(P(x, 0));
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> x;
        num.push_back(P(x, 1));
    }

    sort(num.begin(), num.end());
    for (size_t i = 0; i < n + m - 1; i++)
    {
        if (num[i].second != num[i + 1].second)
        {
            int diff = abs(num[i].first - num[i + 1].first);
            if (dist > diff)
            {
                dist = diff;
                cnt = 1;
            }
            else if (dist == diff)
                cnt++;
        }
    }

    cout << dist + abs(py - qy) << " " << cnt;
}