#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

P p[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 0; tc < T; ++tc)
    {
        int N;
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> p[i].first >> p[i].second;

        sort(p, p + N);

        int ans = 1, second_min = p[0].second;
        for (int i = 1; i < N; ++i)
        {
            if (second_min > p[i].second)
            {
                ++ans;
                second_min = p[i].second;
            }
        }

        cout << ans << '\n';
    }
}

/*

5 5 X
4 1 O
3 2 O
2 3 O
1 4 O

7 3 X
6 1 O
5 7 X
4 2 O
3 6 X
2 5 X
1 4 O

*/