#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int N, K;
    cin >> N >> K;

    vector<vector<int>> cards(N, vector<int>(K));
    for (vector<int> &card : cards)
    {
        for (int &feature : card)
            cin >> feature;
    }

    map<vector<int>, ll> set_cnt;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            vector<int> last_card(K);
            for (int k = 0; k < K; ++k)
            {
                if (cards[i][k] == cards[j][k])
                    last_card[k] = cards[i][k];
                else
                    last_card[k] = 3 - (cards[i][k] + cards[j][k]);
            }

            ++set_cnt[last_card];
        }
    }

    ll ans = 0;
    for (vector<int> &card : cards)
        ans += set_cnt[card] * (set_cnt[card] - 1) / 2;

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    for (int tc = 0; tc < t; ++tc)
        solve();
}

/*



*/