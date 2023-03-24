// 1655번: 가운데를 말해요

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    size_t N;
    cin >> N;

    int mid; // 중앙값
    // 중앙값보다 작은 수를 저장하는 최댓값 힙
    priority_queue<int, vector<int>> max_heap;
    // 중앙값보다 큰 수를 저장하는 최솟값 힙
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (i == 0)
            max_heap.push(num);
        else
            (max_heap.top() < num) ? min_heap.push(num) : max_heap.push(num);

        int hip_diff = abs((long long)(max_heap.size() - min_heap.size()));
        if (hip_diff == 2)
        {
            if (max_heap.size() > min_heap.size())
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }

        hip_diff = abs((long long)(max_heap.size() - min_heap.size()));
        if (hip_diff == 0)
            mid = (max_heap.top() > min_heap.top()) ? min_heap.top() : max_heap.top();
        else if (hip_diff == 1)
            mid = (max_heap.size() < min_heap.size()) ? min_heap.top() : max_heap.top();
        cout << mid << '\n';
    }
}