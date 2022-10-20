#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool graph[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int nA, nB, M;
    cin >> nA >> nB >> M;
    for (int i = 0; i < M; ++i)
    {
        int A, B;
        cin >> A >> B;
        graph[A][B] = true;
    }

    int ans = (nA / 2) + (nB / 2);
    if (nA % 2 == 1 && nB % 2 == 1)
    {
        bool flag = false;
        for (int i = 1; i <= nA; i += 2)
        {
            for (int j = 1; j <= nB; j += 2)
            {
                if (graph[i][j])
                    flag = true;
            }
        }

        ans += flag;
    }

    cout << ans << '\n';
}

/*



*/