#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, C, W[30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> C;
    for (int i = 0; i < N; ++i)
        cin >> W[i];

    if (N == 1)
        cout << 1 + (W[0] <= C) << '\n';
    else
    {
        vector<int> lsum, rsum;
        int l_size = N / 2;
        int r_size = (N % 2 == 0) ? N / 2 : N / 2 + 1;

        for (int i = 0; i < (1 << l_size); ++i)
        {
            int sum = 0;
            for (int j = 0; j < l_size; ++j)
            {
                if (i & (1 << j))
                {
                    if (sum + W[j] > C)
                        break;
                    sum += W[j];
                }
                if (j == l_size - 1)
                    lsum.push_back(sum);
            }
        }
        for (int i = 0; i < (1 << r_size); ++i)
        {
            int sum = 0;
            for (int j = 0; j < r_size; ++j)
            {
                if (i & (1 << j))
                {
                    if (sum + W[j + l_size] > C)
                        break;
                    sum += W[j + l_size];
                }
                if (j == r_size - 1)
                    rsum.push_back(sum);
            }
        }

        sort(rsum.begin(), rsum.end());

        int ans = 0;
        for (int i = 0; i < lsum.size(); ++i)
            ans += upper_bound(rsum.begin(), rsum.end(), C - lsum[i]) - rsum.begin();

        cout << ans << '\n';
    }
}