#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct document
{
    int order;
    int priority;
};

int main()
{
    size_t T, N, M;
    cin >> T;

    int poped_order;
    int prior;
    int print_order;
    for (size_t i = 0; i < T; i++)
    {
        cin >> N >> M;

        queue<document> Q;
        vector<int> PQ(N); // 우선순위 큐로 대체할 수도 있다.
        for (int j = 0; j < N; j++)
        {
            cin >> prior;
            Q.push({j, prior});
            PQ[j] = prior;
        }
        sort(PQ.begin(), PQ.end());

        print_order = 0;
        poped_order = -1;
        while (poped_order != M)
        {
            if (PQ.back() == Q.front().priority)
            {
                print_order++;
                poped_order = Q.front().order;
                Q.pop();
                PQ.pop_back();
            }
            else
            {
                document tmp = Q.front();
                Q.pop();
                Q.push(tmp);
            }
        }

        cout << print_order << '\n';
    }
}