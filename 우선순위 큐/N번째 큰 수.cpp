// 2075번: N번째 큰 수
// 정해
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, num;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> num;
            pq.push(num);
        }

        if (i > 0)
        {
            for (size_t j = 0; j < N; j++)
                pq.pop();
        }
    }

    cout << pq.top();
}

// 쉬운 방법
/*

#include <iostream>
#include <algorithm>
using namespace std;

int nums[2250000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (size_t i = 0; i < N * N; i++)
        cin >> nums[i];

    sort(nums, nums + (N * N));
    cout << nums[(N * N) - N];
}

*/