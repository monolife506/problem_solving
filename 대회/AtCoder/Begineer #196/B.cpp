#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string X;
    cin >> X;

    for (auto c : X)
    {
        if (c == '.')
            break;

        cout << c;
    }

    cout << '\n';
}