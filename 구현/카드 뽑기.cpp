#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; ++tc)
    {
        string cards[4];
        for (size_t i = 0; i < 4; ++i)
            cin >> cards[i];

        bool flag = false;
        for (int i = 0; i + 1 < 4; ++i)
        {
            for (int j = i + 1; j < 4; ++j)
            {
                int k = -1, l = -1;
                for (int idx = 0; idx < 4; ++idx)
                {
                    if (idx == i || idx == j)
                        continue;

                    if (k == -1)
                        k = idx;
                    else // l == -1
                        l = idx;
                }

                if (cards[i] == cards[j] && cards[k] == cards[l])
                    flag = true;
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            int j = -1, k = -1, l = -1;
            for (int idx = 0; idx < 4; ++idx)
            {
                if (idx == i)
                    continue;

                if (j == -1)
                    j = idx;
                else if (k == -1)
                    k = idx;
                else // l == -1
                    l = idx;
            }

            if (cards[j] == cards[k] && cards[k] == cards[l])
                flag = true;

            if (cards[j][1] == cards[k][1] && cards[k][1] == cards[l][1])
            {
                int num[3] = {cards[j][0], cards[k][0], cards[l][0]};
                sort(num, num + 3);

                if (num[0] + 1 == num[1] && num[1] + 1 == num[2])
                    flag = true;
            }
        }

        cout << (flag ? ":)" : ":(") << '\n';
    }
}