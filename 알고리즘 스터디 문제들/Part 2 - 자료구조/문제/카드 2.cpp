#include <iostream>
#include <queue>
using namespace std;

int main()
{
    size_t N;
    cin >> N;

    queue<int> Q;
    for (size_t i = 1; i <= N; i++)
        Q.push(i);

    int tmp;
    while (Q.size() > 1)
    {
        Q.pop();
        tmp = Q.front();
        Q.pop();
        Q.push(tmp);
    }
    cout << Q.front();
}