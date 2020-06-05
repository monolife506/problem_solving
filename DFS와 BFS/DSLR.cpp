// 9019번: DSLR

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

namespace reg
{
    int *getDigit(int num)
    {
        static int d[4];
        int digit = 1000;
        for (size_t i = 0; i < 4; i++)
        {
            d[i] = num / digit;
            num %= digit;
            digit /= 10;
        }

        return d;
    }
    int D(int num)
    {
        num *= 2;
        if (num >= 10000)
            num %= 10000;
        return num;
    }
    int S(int num)
    {
        num -= 1;
        if (num < 0)
            num = 9999;
        return num;
    }
    int L(int num)
    {
        int *d = getDigit(num);
        num = d[1] * 1000 + d[2] * 100 + d[3] * 10 + d[0];
        return num;
    }
    int R(int num)
    {
        int *d = getDigit(num);
        num = d[3] * 1000 + d[0] * 100 + d[1] * 10 + d[2];
        return num;
    }
} // namespace reg

int cal(int idx, int num)
{
    switch (idx)
    {
    case 0:
        return reg::D(num);
    case 1:
        return reg::S(num);
    case 2:
        return reg::L(num);
    case 3:
        return reg::R(num);
    default:
        return -1;
        break;
    }
}

void BFS(int start, int target, int *pre, char *oper)
{
    queue<int> Q;
    bool visited[10000] = {};
    char now[4] = {'D', 'S', 'L', 'R'};

    pre[start] = -1;
    visited[start] = true;
    Q.push(start);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int next = cal(i, cur);
            if (!visited[next])
            {
                pre[next] = cur;
                oper[next] = now[i];
                visited[next] = true;

                if (next == target)
                    return;
                else
                    Q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;

        int pre[10000];
        char oper[10000];
        BFS(A, B, pre, oper);

        stack<char> output;
        while (pre[B] != -1)
        {
            output.push(oper[B]);
            B = pre[B];
        }

        while (!output.empty())
        {
            cout << output.top();
            output.pop();
        }

        cout << '\n';
    }
}