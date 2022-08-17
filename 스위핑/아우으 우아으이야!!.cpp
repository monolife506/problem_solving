#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

P line[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> line[i].first >> line[i].second;

    sort(line, line + N);

    int ans = 0, l = line[0].first, r = line[0].second;
    for (int i = 1; i < N; ++i)
    {
        if (line[i].first <= r)
        {
            r = max(r, line[i].second);
        }
        else
        {
            ans += (r - l);
            l = line[i].first;
            r = line[i].second;
        }
    }

    ans += (r - l);
    cout << ans << '\n';
}