// 11286번: 절댓값 힙

#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(int A, int B)
    {
        int absA = abs(A);
        int absB = abs(B);
        return (absA != absB) ? (absA > absB) : (A > B);
    }
};

int main()
{
    size_t N;
    priority_queue<int, vector<int>, cmp> pq;
    scanf("%d", &N);

    for (size_t i = 0; i < N; i++)
    {
        int input;
        scanf("%d", &input);

        if (input != 0)
            pq.push(input);
        else
        {
            if (pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
    }
}