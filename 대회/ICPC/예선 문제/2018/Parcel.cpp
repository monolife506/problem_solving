#include <iostream>
using namespace std;

struct Check
{
    int a;
    int b;
    bool flag = false;
};

int W, N;
int A[5000];
Check check[900002];

bool ans = false;

int main()
{
    cin >> W >> N;
    for (size_t i = 0; i < N; i++)
        cin >> A[i];

    // c + d 탐색
    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            int cur = A[i] + A[j];
            check[cur].a = A[i];
            check[cur].b = A[j];
            check[cur].flag = true;
        }
    }

    // a + b 탐색
    for (size_t i = 0; i < N - 1; i++)
    {
        for (size_t j = i + 1; j < N; j++)
        {
            int cur = W - (A[i] + A[j]);
            if (cur >= 0)
            {
                if (check[cur].a != A[i] && check[cur].a != A[j] &&
                    check[cur].b != A[j] && check[cur].b != A[i] && check[cur].flag)
                    ans = true;
            }
        }
    }

    cout << (ans ? "YES" : "NO");
}

// a + b + c + d = w
// (a + b) = w - (c + d)
