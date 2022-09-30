#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    for (int tc = 0; tc < q; ++tc)
    {
        int n;
        cin >> n;

        string t, decoded;
        cin >> t;
        for (int i = t.length() - 1; i >= 0; --i)
        {
            if (t[i] == '0')
            {
                decoded.push_back((t[i - 2] - '0') * 10 + (t[i - 1] - '0') - 1 + 'a');
                i -= 2;
            }
            else
            {
                decoded.push_back(t[i] - '0' - 1 + 'a');
            }
        }

        for (int i = decoded.length() - 1; i >= 0; --i)
            cout << decoded[i];

        cout << '\n';
    }
}