#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

ll a[100001], psum[2][100001];
stack<int> s[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        cin >> a[i];
        psum[0][i] += psum[0][i - 1] + a[i];

        ++cnt;
        if (a[i] % M == 0)
        {
            if (i + (a[i] / M) <= N)
                s[i + (a[i] / M)].push(i);
        }
        else
        {
            if (i + (a[i] / M + 1) <= N)
                s[i + (a[i] / M + 1)].push(i);
        }

        ll val = 0;
        val += 1LL * (cnt - 1) * M;
        while (!s[i].empty())
        {
            --cnt;
            val += a[s[i].top()];
            val -= 1LL * (i - s[i].top()) * M;
            s[i].pop();
        }

        psum[1][i] = psum[1][i - 1] + val;
    }

    for (int i = 0; i < Q; ++i)
    {
        int q, t;
        cin >> q >> t;
        if (q == 1)
            cout << psum[0][t] - psum[1][t] << '\n';
        else
            cout << psum[1][t] - psum[1][t - 1] << '\n';
    }
}

/*

*/