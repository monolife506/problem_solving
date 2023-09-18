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

    if (S.substr(S.size() - 2, 2) == "er")
        cout << "er" << '\n';
    else if (S.size() >= 3 && S.substr(S.size() - 3, 3) == "ist")
        cout << "ist" << '\n';
}