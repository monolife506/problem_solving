#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; ++i)
        q.push(i);

    int cnt = 1;
    vector<int> ans;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cnt != K)
        {
            q.push(cur);
            ++cnt;
        }
        else
        {
            ans.push_back(cur);
            cnt = 1;
        }
    }

    if (ans.size() == 1)
    {
        cout << "<" << ans[0] << ">" << '\n';
    }
    else
    {
        for (int i = 0; i < ans.size(); ++i)
        {
            if (i == 0)
                cout << "<" << ans[i] << ", ";
            else if (i == ans.size() - 1)
                cout << ans[i] << ">\n";
            else
                cout << ans[i] << ", ";
        }
    }
}