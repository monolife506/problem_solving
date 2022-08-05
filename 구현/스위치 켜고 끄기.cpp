#include <iostream>
using namespace std;

bool s[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> s[i];

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int gender, num;
        cin >> gender >> num;
        if (gender == 1)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (j % num == 0)
                    s[j] = !s[j];
            }
        }
        else
        {
            int l = num;
            int r = num;
            while (true)
            {
                if (l - 1 < 1 || r + 1 > N)
                    break;
                if (s[l - 1] != s[r + 1])
                    break;

                --l;
                ++r;
            }
            for (int j = l; j <= r; ++j)
            {
                s[j] = !s[j];
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << s[i] << " ";
        if (i % 20 == 0)
            cout << '\n';
    }

    cout << '\n';
}