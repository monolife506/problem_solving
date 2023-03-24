#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
    {
        string s;
        cin >> s;

        vector<int> ans;
        ans.push_back(1);

        if (s.front() < s.back())
        {
            for (char c = s.front(); c <= s.back(); ++c)
            {
                for (int i = 1; i < s.length() - 1; ++i)
                {
                    if (s[i] == c)
                        ans.push_back(i + 1);
                }
            }
        }
        else
        {
            for (char c = s.front(); c >= s.back(); --c)
            {
                for (int i = 1; i < s.length() - 1; ++i)
                {
                    if (s[i] == c)
                        ans.push_back(i + 1);
                }
            }
        }

        ans.push_back(s.length());

        cout << abs(s.front() - s.back()) << " " << ans.size() << '\n';
        for (int i : ans)
            cout << i << " ";

        cout << '\n';
    }
}