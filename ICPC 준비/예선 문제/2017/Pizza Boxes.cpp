#include <iostream>
using namespace std;
typedef long long ll;

int n, m;
int box[1000][1000];

int maxn[1000];
int maxm[1000];

int main()
{
    ll ans = 0;
    cin >> n >> m;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> box[i][j];
            ans += box[i][j];
            if (box[i][j] > maxn[i])
                maxn[i] = box[i][j];
            if (box[i][j] > maxm[j])
                maxm[j] = box[i][j];
        }
    }

    for (size_t i = 0; i < n; i++)
        ans -= maxn[i];
    for (size_t j = 0; j < m; j++)
    {
        ans -= maxm[j];
        for (size_t i = 0; i < n; i++)
        {
            if (maxm[j] == maxn[i])
            {
                ans += maxm[j];
                break;
            }
        }
    }

    cout << ans;
}

// 00 10 10 90 10
// 10
// 90
// 10
// 10