#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    map<string, int> cnt;
    for (int i = 0; i < N; ++i)
    {
        string name;
        cin >> name;

        if (cnt.find(name) == cnt.end())
            cnt[name] = 1;
        else
            ++cnt[name];
    }

    string ans;
    int max_cnt = 0;
    for (pair<const string, int> &p : cnt)
    {
        if (p.second > max_cnt)
        {
            ans = p.first;
            max_cnt = p.second;
        }
    }

    cout << ans << '\n';
}