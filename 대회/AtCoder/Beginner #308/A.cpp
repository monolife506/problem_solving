#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> S(8);
    for (int i = 0; i < 8; ++i)
        cin >> S[i];

    if (S[0] % 25 != 0 || S[0] < 100 || S[0] > 675)
    {
        cout << "No" << '\n';
        return 0;
    }
    for (int i = 1; i < 8; ++i)
    {
        if (S[i - 1] > S[i] || S[i] % 25 != 0 || S[i] < 100 || S[i] > 675)
        {
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';
}