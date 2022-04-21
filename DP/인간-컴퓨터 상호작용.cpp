#include <iostream>
#include <string>
using namespace std;

int psum[26][200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    cin >> S;
    for (size_t i = 0; i < S.length(); ++i)
    {
        for (size_t j = 0; j < 26; ++j)
        {
            if (S[i] - 'a' == j)
                ++psum[j][i + 1];
            psum[j][i + 1] += psum[j][i];
        }
    }

    size_t q;
    cin >> q;
    for (size_t i = 0; i < q; ++i)
    {
        char a;
        int l, r;
        cin >> a >> l >> r;
        cout << psum[a - 'a'][r + 1] - psum[a - 'a'][l] << '\n';
    }
}