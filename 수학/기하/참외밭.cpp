#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K;
    cin >> K;

    P p[6];
    for (int i = 0; i < 6; ++i)
        cin >> p[i].first >> p[i].second;

    int x[2] = {}, y[2] = {};
    for (int i = 0; i < 6; ++i)
    {
        int pre = (i + 5) % 6;
        int nxt = (i + 1) % 6;

        if (p[i].first == 1 || p[i].first == 2)
        {
            x[0] = max(x[0], p[i].second);
        }
        else
        {
            y[0] = max(y[0], p[i].second);
            if (p[pre].first == p[nxt].first)
            {
                y[1] = p[i].second;
                if (p[pre].first == 1)
                {
                    if (p[i].first == 3)
                        x[1] = p[pre].second;
                    else
                        x[1] = p[nxt].second;
                }
                else if (p[pre].first == 2)
                {
                    if (p[i].first == 3)
                        x[1] = p[nxt].second;
                    else
                        x[1] = p[pre].second;
                }
            }
        }
    }

    cout << K * (x[0] * y[0] - x[1] * y[1]) << '\n';
}

/*

1 3 1
1 4 1
2 3 2
2 4 2

*/