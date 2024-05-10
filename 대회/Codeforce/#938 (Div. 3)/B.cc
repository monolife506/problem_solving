#include <bits/stdc++.h>
// #define FILE_RW
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;

    map<int, int> nums;
    vector<int> b(n * n);
    for (auto &bi : b)
    {
        cin >> bi;
        nums[bi]++;
    }

    vector<vector<int>> matrix(n, vector<int>(n));
    matrix[0][0] = *min_element(b.begin(), b.end());
    nums[matrix[0][0]]--;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 && j == 0)
                continue;

            if (i != 0 && nums[matrix[i - 1][j] + c] == 0)
            {
                cout << "NO" << '\n';
                return;
            }

            if (j != 0 && nums[matrix[i][j - 1] + d] == 0)
            {
                cout << "NO" << '\n';
                return;
            }

            if (i != 0 && j != 0 && matrix[i - 1][j] + c != matrix[i][j - 1] + d)
            {
                cout << "NO" << '\n';
                return;
            }

            if (i != 0)
            {
                nums[matrix[i - 1][j] + c]--;
                matrix[i][j] = matrix[i - 1][j] + c;
            }
            else
            {
                matrix[i][j] = matrix[i][j - 1] + d;
                nums[matrix[i][j - 1] + d]--;
            }
        }
    }

    cout << "YES" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef FILE_RW
    freopen("local.in", "r", stdin);
    freopen("local.out", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc)
        solve();
}