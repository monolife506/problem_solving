// 4195번: 친구 네트워크

#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

int root[200002];
unordered_map<string, int> table;

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
        if (getSize(A) < getSize(B))
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

    int T, F, hashNum;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++)
    {
        memset(root, -1, sizeof(root));
        table.clear();
        hashNum = 0;

        cin >> F;
        for (size_t i = 0; i < F; i++)
        {
            string A, B;
            cin >> A >> B;
            table.insert(make_pair(A, hashNum++));
            table.insert(make_pair(B, hashNum++));

            int numA = table[A];
            int numB = table[B];

            merge(numA, numB);
            cout << getSize(numA) << '\n';
        }
    }
}