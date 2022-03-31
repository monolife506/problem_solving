#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, C, H, K;
int root[100001];

int getRoot(int N)
{
    if (root[N] < 0)
        return N;
    return root[N] = getRoot(root[N]);
}

int getSize(int N)
{
    return abs(root[getRoot(N)]);
}

void merge(int A, int B)
{
    A = getRoot(A);
    B = getRoot(B);
    if (A != B)
    {
        if (A == H)
        {
            root[A] += root[B];
            root[B] = A;
        }
        else if (B == H)
        {
            root[B] += root[A];
            root[A] = B;
        }
        else if (A == C)
        {
            root[A] += root[B];
            root[B] = A;
        }
        else if (B == C)
        {
            root[B] += root[A];
            root[A] = B;
        }
        else
        {
            root[A] += root[B];
            root[B] = A;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(root, -1, sizeof(root));

    cin >> N >> M;
    for (size_t i = 0; i < M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        merge(X, Y);
    }

    cin >> C >> H >> K;

    priority_queue<int> pq;
    for (size_t i = 1; i <= N; i++)
    {
        if (i == getRoot(i) && i != C && i != H)
            pq.push(getSize(i));
    }

    int maxPower = getSize(C);
    for (size_t i = 0; i < K; i++)
    {
        if (pq.empty())
            break;

        maxPower += pq.top();
        pq.pop();
    }

    cout << maxPower;
}