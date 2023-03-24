// 1976번: 여행 가자

#include <iostream>
#include <cstring>
using namespace std;

int root[201];
int plan[2000];

int find(int N)
{
    if (root[N] == -1)
        return N;
    return root[N] = find(root[N]);
}

void merge(int A, int B)
{
    int rootA = find(A);
    int rootB = find(B);
    if (rootA != rootB)
        root[rootA] = rootB;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(root, -1, sizeof(root));

    bool con;
    int N, M;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j <= N; j++)
        {
            cin >> con;
            if (con == 1)
                merge(i, j);
        }
    }

    for (size_t i = 0; i < M; i++)
        cin >> plan[i];
    for (size_t i = 0; i < M - 1; i++)
    {
        if (find(plan[i]) != find(plan[i + 1]))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}