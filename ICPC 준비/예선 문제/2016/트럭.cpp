#include <iostream>
#include <queue>
using namespace std;

int truck[1000];

int main()
{
    int n, w, L, curW = 0, sec = 0;
    cin >> n >> w >> L;
    for (size_t i = 0; i < n; i++)
        cin >> truck[i];

    queue<int> bridge;
    for (size_t i = 0; i < n; i++)
    {
        if (curW + truck[i] <= L &&)
        {
            curW += truck[i];

            bridge.push();
        }
        else
        {
        }
    }
}