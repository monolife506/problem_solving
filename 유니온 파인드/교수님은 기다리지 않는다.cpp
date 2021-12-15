#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAX_N = 100000;
const ll INF = INT64_MAX;

int root[MAX_N + 1];
ll diff[MAX_N + 1];

int find(int n)
{
    if (root[n] == -1)
        return n;

    int next = find(root[n]);
    diff[n] += diff[root[n]];
    return root[n] = next;
}

void test(int a, int b, int w)
{
    int root_a = find(a);
    int root_b = find(b);

    if (root_a != root_b)
    {
        diff[root_b] = (diff[a] + w) - diff[b];
        root[root_b] = root_a;
    }
}

ll question(int a, int b)
{
    if (find(a) != find(b))
        return INF;

    return diff[b] - diff[a];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    while (N != 0 || M != 0)
    {
        memset(root, -1, sizeof(root));
        memset(diff, 0, sizeof(diff));

        for (size_t i = 0; i < M; i++)
        {
            char query;
            cin >> query;

            if (query == '!')
            {
                int a, b, w;
                cin >> a >> b >> w;
                test(a, b, w);
            }
            else // query == '?'
            {
                int a, b;
                ll ans;
                cin >> a >> b;

                ans = question(a, b);

                if (ans != INF)
                    cout << ans << '\n';
                else
                    cout << "UNKNOWN" << '\n';
            }
        }

        cin >> N >> M;
    }
}

/*
4 7
! 1 2 1
! 3 4 -1
! 2 4 2
? 2 4 
? 1 3 
? 1 4 
? 2 3 
0 0

2
4
3
3

7 9
! 1 2 100
! 2 3 100
! 4 3 150
! 6 7 50
! 5 6 50
! 5 4 10
? 5 3
? 5 7
? 1 5
0 0

160
100
40

*/