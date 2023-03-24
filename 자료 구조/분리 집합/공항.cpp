// 10775번: 공항

#include <iostream>
#include <cstring>
using namespace std;

int ans;
int plane[100001];
int root[100001];

int find(int N)
{
    if (root[N] < 0)
        return N;
    return root[N] = find(root[N]);
}

void merge(int A, int B)
{
    A = find(A);
    B = find(B);
    if (A != B)
        root[A] = B;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(root, -1, sizeof(root));

    int G, P;
    cin >> G >> P;
    for (size_t i = 0; i < P; i++)
        cin >> plane[i];

    for (size_t i = 0; i < P; i++)
    {
        int emptyGate = find(plane[i]);
        if (emptyGate != 0)
        {
            ans++;
            merge(emptyGate, emptyGate - 1); // 더 작은 게이트의 번호를 root로
        }
        else
            break;
    }

    cout << ans;
}

// Simple Greedy? (gi부터 살펴보기) -> N(O^2)
// Disjoint set 이용?