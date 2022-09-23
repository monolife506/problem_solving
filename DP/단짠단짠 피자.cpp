#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int A[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, K;
    cin >> N >> Q >> K;
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    ll val = 0, odd_cnt = 0, even_cnt = 0;
    for (int i = 0; i < K; ++i)
    {
        val += A[i];
        if (i % 2 == 0)
            ++even_cnt;
        else
            ++odd_cnt;
    }

    map<pii, pii> candidates;
    candidates.insert({{odd_cnt, even_cnt}, {0, val}});
    if (K != N)
    {
        for (int i = 1; i < N; ++i)
        {
            val -= A[i - 1];
            if ((i - 1) % 2 == 0)
                --even_cnt;
            else
                --odd_cnt;

            val += A[(i + K - 1) % N];
            if (((i + K - 1) % N) % 2 == 0)
                ++even_cnt;
            else
                ++odd_cnt;

            if (candidates.find({odd_cnt, even_cnt}) == candidates.end())
                candidates.insert({{odd_cnt, even_cnt}, {i, val}});
            else if (candidates[{odd_cnt, even_cnt}].second < val)
                candidates[{odd_cnt, even_cnt}] = {i, val};
        }
    }

    ll odd_val = 0, even_val = 0;
    for (int q = 0; q < Q; ++q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            even_val += x;
        }
        else if (t == 2)
        {
            int x;
            cin >> x;
            odd_val += x;
        }
        else // t == 3
        {
            pii ans = {-1, INT64_MIN};
            for (pair<const pii, pii> &p : candidates)
            {
                if (ans.second < p.second.second + p.first.first * odd_val + p.first.second * even_val)
                    ans = {p.second.first, p.second.second + p.first.first * odd_val + p.first.second * even_val};
                else if (ans.second == p.second.second + p.first.first * odd_val + p.first.second * even_val && ans.first > p.second.first)
                    ans.first = p.second.first;
            }

            cout << ans.first + 1 << " " << ans.second << '\n';
        }
    }
}

/*

5 1 2
10 10 -100 10 10
3

*/