#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> P;

vector<vector<P>> tree;

int getAns(int cur, int parent)
{
    if (tree[cur].size() == 1 && cur != 1) // leaf node
        return 21;

    int sum = 0;
    for (P next : tree[cur]) {
        if (next.first != parent)
            sum += min(next.second, getAns(next.first, cur));
    }

    return sum;
}

int main()
{
    size_t T;
    cin >> T;
    for (size_t tc = 0; tc < T; tc++) {
        int N, M;
        cin >> N >> M;

        tree.clear();
        tree.resize(N + 1);

        for (size_t i = 0; i < M; i++) {
            int A, B, D;
            cin >> A >> B >> D;
            tree[A].push_back(P(B, D));
            tree[B].push_back(P(A, D));
        }

        cout << getAns(1, 0) << '\n';
    }
}