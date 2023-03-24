#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    map<ll, int> cnt;
    for (int i = 0; i < N; ++i)
    {
        ll num;
        cin >> num;
        if (cnt.find(num) == cnt.end())
            cnt[num] = 1;
        else
            ++cnt[num];
    }

    ll ans;
    int max_cnt = 0;
    for (pair<const ll, int> &p : cnt)
    {
        if (p.second > max_cnt)
        {
            ans = p.first;
            max_cnt = p.second;
        }
    }

    cout << ans << '\n';
}