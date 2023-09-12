#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int A[300001];
vector<int> idx[300001];
set<int> nums;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        idx[A[i]].push_back(i);
        nums.insert(A[i]);
    }

    ll ans = 0;
    for (auto num : nums)
    {
        ll l = 1;
        ll r = idx[num].size() - 1;
        for (int i = 0; i < idx[num].size() - 1; ++i)
        {
            ans += l * r * (idx[num][i + 1] - idx[num][i] - 1);
            ++l;
            --r;
        }
    }

    cout << ans << '\n';
}

/*

8
1 2 3 1 4 5 1 6 1 7 1

2 2 1 1

5
1 2 1 3 2


1
2


*/