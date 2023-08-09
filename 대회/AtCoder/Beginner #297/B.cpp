#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    int x = -1, y = -1;
    int k = -1;
    int r1 = -1, r2 = -1;
    for (int i = 0; i < 8; ++i)
    {
        if (S[i] == 'B')
        {
            if (x == -1)
                x = i;
            else
                y = i;
        }
        else if (S[i] == 'K')
        {
            k = i;
        }
        else if (S[i] == 'R')
        {
            if (r1 == -1)
                r1 = i;
            else
                r2 = i;
        }
    }

    if (x % 2 != y % 2 && r1 < k && k < r2)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}