// 1717번: 집합의 표현
// 유니온 파인드 연습

#include <iostream>
#include <cstring>
using namespace std;

int root[1000001];

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

    int N, M;
    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int query, A, B;
        cin >> query >> A >> B;

        switch (query)
        {
        case 0:
            merge(A, B);
            break;

        case 1:
            if (find(A) == find(B))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
            break;
        }
    }
}