// 1927번: 최소 힙

#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    size_t N;
    priority_queue<int, vector<int>, greater<int>> Q;
    scanf("%d", &N);

    for (size_t i = 0; i < N; i++)
    {
        int input;
        scanf("%d", &input);

        if (input != 0)
            Q.push(input);
        else
        {
            if (Q.empty())
                printf("0\n");
            else
            {
                printf("%d\n", Q.top());
                Q.pop();
            }
        }
    }
}