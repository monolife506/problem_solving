#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool cmp(pair<pii, int> &lhs, pair<pii, int> &rhs)
{
    ll lval = 1LL * lhs.first.first * rhs.first.second;
    ll rval = 1LL * rhs.first.first * lhs.first.second;

    return (lval != rval) ? lval > rval : lhs.second < rhs.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<pii, int>> v;
    for (int i = 1; i <= N; ++i)
    {
        int A, B;
        cin >> A >> B;
        v.push_back(make_pair(pii(A, (A + B)), i));
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < N; ++i)
        cout << v[i].second << " ";

    cout << '\n';
}