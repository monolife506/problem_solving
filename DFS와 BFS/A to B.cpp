// 16953번: A → B

#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

ll A, B;
int BFS(int start, int target)
{
    queue<P> Q;
    Q.push(P(start, 1));

    while (!Q.empty())
    {
        P cur = Q.front();
        Q.pop();

        if (cur.first > target)
            continue;

        if (cur.first == target)
            return cur.second;

        Q.push(P(cur.first * 2, cur.second + 1));
        Q.push(P(cur.first * 10 + 1, cur.second + 1));
    }

    return -1;
}

int main()
{
    cin >> A >> B;
    cout << BFS(A, B);
}
