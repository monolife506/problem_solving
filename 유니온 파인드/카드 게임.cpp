#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int N, M, K;
int card[4000001];
int root[4000001];

int find(int cur)
{
    if (root[cur] == -1)
        return cur;
    return root[cur] = find(root[cur]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(root, -1, sizeof(root));

    cin >> N >> M >> K;
    for (size_t i = 0; i < M; i++)
        cin >> card[i];

    sort(card, card + N);
    for (size_t i = 0; i < K; i++) {
        int target, idx;
        cin >> target;
        idx = (int)(upper_bound(card, card + N, target) - card);
        idx = find(idx);
        cout << card[idx] << '\n';
        root[idx] = idx + 1;
    }
}