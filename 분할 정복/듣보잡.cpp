// 1764번: 듣보잡

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<string> str(N);
    vector<string> ans;
    for (size_t i = 0; i < N; i++)
        cin >> str[i];

    sort(str.begin(), str.end());
    for (size_t i = 0; i < M; i++)
    {
        string input;
        cin >> input;
        if (binary_search(str.begin(), str.end(), input))
            ans.push_back(input);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}