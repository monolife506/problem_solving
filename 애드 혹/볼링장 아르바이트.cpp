#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> w(N);
    int max_idx = 0;
    int max_val = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> w[i];
        if (max_val <= w[i])
        {
            max_idx = i;
            max_val = w[i];
        }
    }

    vector<int> w_sorted = w;
    sort(w_sorted.begin(), w_sorted.end());

    int sorted_cnt = 1;
    int order = N - 2;
    for (int i = max_idx - 1; i >= 0; --i)
    {
        if (w[i] == w_sorted[order])
        {
            sorted_cnt++;
            order--;
        }
    }

    cout << N - sorted_cnt << '\n';
}