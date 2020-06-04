#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main()
{
    size_t N, M;
    cin >> N >> M;

    deque<int> D;
    for (size_t i = 1; i <= N; i++)
        D.push_back(i);

    int num;
    queue<int> pop_num;
    for (size_t i = 0; i < M; i++)
    {
        cin >> num;
        pop_num.push(num);
    }

    int target, diff;
    int cnt = 0;
    while (!pop_num.empty())
    {
        target = pop_num.front();
        if (target == D.front())
        {
            D.pop_front();
            pop_num.pop();
        }
        else
        {
            diff = 0;
            for (int i = 0; i < D.size(); i++)
            {
                if (target != D[i])
                    diff++;
                else
                    break;
            }

            if (diff <= D.size() / 2)
            {
                // 왼쪽으로 한칸
                while (target != D.front())
                {
                    num = D.front();
                    D.pop_front();
                    D.push_back(num);
                    cnt++;
                }
            }
            else
            {
                // 오른쪽으로 한칸
                while (target != D.front())
                {
                    num = D.back();
                    D.pop_back();
                    D.push_front(num);
                    cnt++;
                }
            }

            // 여기서 조금 더 생각하면, 큐만으로 문제를 해결할 수도 있습니다.
        }
    }

    cout << cnt;
}