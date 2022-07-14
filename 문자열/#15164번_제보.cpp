#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

void manacher(const string &S, vector<int> &p)
{
    p.resize(S.size() * 2 + 1);

    string tmp = "|";
    for (const char &c : S)
    {
        tmp.push_back(c);
        tmp.push_back('|');
    }

    int c = -1, r = -1;
    for (int i = 0; i < tmp.size(); ++i)
    {
        if (r < i)
        {
            p[i] = 0;
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < tmp.size() && tmp[i - p[i] - 1] == tmp[i + p[i] + 1])
                ++p[i];

            c = i;
            r = i + p[i];
        }
        else // r >= i
        {
            p[i] = min(r - i, p[c * 2 - i]);
            if (p[c * 2 - i] == r - i)
            {
                while (i - p[i] - 1 >= 0 && i + p[i] + 1 < tmp.size() && tmp[i - p[i] - 1] == tmp[i + p[i] + 1])
                    ++p[i];

                c = i;
                r = i + p[i];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;

    vector<int> p;
    manacher(S, p);

    ll ans = S.length();
    for (int i = 0; i < p.size(); ++i)
        ans += p[i] / 2;

    cout << ans << '\n';
}

/*

@ A @ B @ C @ B @ A @
0 1 0 1 0 5 0 1 0 1 0

@ A @ A @ B @ B @
0 1 2 1 0 1 2 1 0

*/
